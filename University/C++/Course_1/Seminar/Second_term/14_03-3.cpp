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

template <typename x> void arrcin(x* a, int n) {
    for (int i = 0; i < n; i++) {
           cin >> a[i];
    }
}
template <typename x> void arrout(x* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << '\n';
    }
}
template <typename x> x fg(int n, x t) {
        x *a = new x [n];
        return *a;
}

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cin.tie(0);
    ios_base::sync_with_stdio(0);;
    int n, b, m;
    //int a;
    double a;
    cin >> n >> a;
    //int* h = new int[n];
    double* h = new double[n];
    *h = fg(n, a);
    arrcin(h, n);
    arrout(h, n);
    return 0;
}
