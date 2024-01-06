#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> a = { 12, 34, 56, 78, 90 };
    int firstDigit = a[0] % 10;
    a[a.size() - 2] = firstDigit;

    for (int num : a) {
        cout << num << " ";
    }

    return 0;
}
