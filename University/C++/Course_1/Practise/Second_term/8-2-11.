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

double rec(int d, int n, double x) {
	if (d == n)
		return x/(d + x);
	else
		return x / (d + rec(d + 1, n, x));
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cin.tie(0);
	ios_base::sync_with_stdio(0);;
	int n, d = 1;
	double x;
	cin >> n >> x;
	cout << rec(d,n,x);
	return 0;
}
