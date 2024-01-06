#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <fstream>
#include <algorithm>


using namespace std;

int main() {
    int n;
    cin >> n;
    set <int> dz;
    set <int> tz;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for (char z : temp) {
            if (temp.length() == 2)
                dz.insert(int(z - 48));
            else
                if(temp.length() == 3)
                    tz.insert(int(z - 48));
        }
    }
    set <int> answ;
    set_difference(dz.begin(),dz.end(), tz.begin(), tz.end(), inserter(answ, answ.begin()));
    for (auto i : answ) {
        cout << i << ' ';
    }
    return 0;
}
