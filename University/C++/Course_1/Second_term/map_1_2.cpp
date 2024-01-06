#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <Windows.h>
#include <map>

using namespace std;

bool isNumeric(std::string const& str)
{
    auto it = str.begin();
    while (it != str.end() && std::isdigit(*it)) {
        it++;
    }
    return !str.empty() && it == str.end();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    map <string, int> a;
    set<int> temp;
    string s;
    int tt;

    while (fin.peek() != EOF) {
        fin >> s;
        if (!isNumeric(s))
            a[s]++;

    }
    for (auto it = a.begin(); it != a.end(); it++) {
        cout << it->first << ' ' << it->second << '\n';
    }
    return 0;
}
