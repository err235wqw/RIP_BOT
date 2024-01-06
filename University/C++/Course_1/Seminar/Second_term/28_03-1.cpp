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

void ff(int x, int p, int k, int it) {
	if (it <= x + 1) {
		for (int i = 0; i < p; i++)
			cout << ' ';
		for (int i = 0; i < k; i++)
			cout << '*';
		cout << '\n';
		return ff(x, p - 1, k + 2, it + 1);
	}
}

void trs(int n, int x, int p) {
	if (x <= n) {
		ff(x, p, 1, 1);
		return trs(n, x + 1, p);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	trs(n, 1, n);
	return 0;
}
