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
    int n, min, mn;
    cin >> n;
    int *a = new int [n];
    int* b = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        min = 1e10;
        for (int i1 = 0; i1 < n; i1++) {
            if (a[i1] < min) {
                min = a[i1];
                mn = i1;
            }
        }
        a[mn] = 1e10;
        b[i] = min;
    }
    for (int i = 0; i < n; i++) {
        cout << b[i] << '\n';
    }

    return 0;
}
