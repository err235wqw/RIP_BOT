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

void ff(string * a, int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--) {
			if (a[j].size() < a[j - 1].size())
				swap(a[j], a[j - 1]);
			if (a[j].size() == a[j - 1].size()) {
				string a1 = "", a2 = "";
				for (int i1 = 0; i1 < a[j].size(); i1++) {
					a1 += tolower(a[j][i1]); 
					a2 += tolower(a[j - 1][i1]);
				}
				if (a1 < a2) swap(a[j], a[j - 1]);
			}

		}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string * a = new string[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	ff(a, n);
	for (int i = 0; i < n; i++)
		cout << a[i] << '\n';
	return 0;
}
