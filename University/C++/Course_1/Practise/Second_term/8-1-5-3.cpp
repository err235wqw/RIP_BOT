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

int nodr(int a, int b) {
	if (a != b) {
		 return nod(max(a, b) - min(a, b), min(a, b));
	}
	return a;

}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cin.tie(0);
	ios_base::sync_with_stdio(0);;
	int a, b, c, d;
	cin >> a >> b >> d >> c;
	cout << (a * c + d * b) / nodr(a * c + d * b, b * c) << '/' << (b * c) / nodr(a * c + d * b, b * c);
	return 0;
}
