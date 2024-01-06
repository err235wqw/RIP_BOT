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
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cin.tie(0);
	ios_base::sync_with_stdio(0);;
	string s;
	getline(cin,s);
	for (auto i = s.begin(); i != s.end(); i++) {
		if (( * i > 47 && *i < 58) || ( (i + 1) != s.end() && *i == 45 && *(i + 1)>47 && *(i + 1)<58)) {
			cout << *i;
			i++;
			while (i != s.end()) {
				if (*i > 47 && *i < 58) {
					cout << *i;
					i++;
				}
				else {
					i--;
					break;
				}

			}
			cout << '\n';
			if (i == s.end())
				i--;
		}
		
	}
	return 0;
}
