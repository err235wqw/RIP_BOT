#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <cctype>
#include <string>
#include <queue>
#include <deque>
#include <ctime>
#include <Windows.h>
#include <fstream>
#include <array>


using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    ofstream inn("put.bin", ios_base::binary);
    cin >> n;
    x = 1;
    for (int i = 0; i < n; i++) {
        inn.write((char*)&x, sizeof(int));
        x *= 3;
    }
    inn.close();


    int x1,bb = 1;
    ifstream fin("put.bin", ios_base::binary);
    while (fin.peek() != EOF) {
        fin.read((char*)&x1, sizeof(int));
        if (bb%2==0) {
            cout << x1 << '\n';
        }
        bb++;
    }

    fin.close();
    return 0;


}
