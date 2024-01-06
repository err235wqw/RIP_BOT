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

template <typename x> void arrcin(x** a, int n, int m) {
    for (int i = 0; i < n; i++) {
        a[i] = new x[m];
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
}


template <typename x> void arrcout(x** p, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << p[i][j] << ' ';
        }
        cout << endl;
    }
}

template <typename x> void lol(x** p, int n, int m, x a) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (p[i][j] < a ) {
                p[i][j] = a;
            }

        }
    }
}


int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cin.tie(0);
    ios_base::sync_with_stdio(0);;
    int n, a, b, m;
    cin >> n >> m >> a;
    int** p = new int* [n];
    arrcin(p, n, m);
    lol(p, n, m, a);
    arrcout(p, n, m);
    return 0;
}
