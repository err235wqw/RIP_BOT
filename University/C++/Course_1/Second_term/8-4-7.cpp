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

double func(double x) {
	if (x >= 0) {
		if (x >= 1) {
			return 2;
		}
		return x * x + 3*x +4;
	}
	return -4;
}
void func(double x, double& a) {
	if (x < 0)
		a = -4;
	if (x >= 0 && x < 1)
		a = x * x + 3 * x + 4;
	if (x >= 1)
		a = 2;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cin.tie(0);
	ios_base::sync_with_stdio(0);;
	double a, b, h, a1;
	cin >> a >> b >> h;
	for (double i = min(a, b); i <= max(a, b); i += h) {
		cout << i << ' ' << func(i) << endl;
		func(i, a1);
		cout << i << ' '<< a1 << '\n';
	}
	return 0;
}
