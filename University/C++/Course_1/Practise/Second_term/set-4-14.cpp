#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    vector<set<int>> usull;
    set<int> temp;
    string s;
    int tt;

    while (fin.peek() != EOF) {
        fin >> s;
        if (fin.peek() == '\n') {
            
            temp.insert(stoi(s));
            usull.push_back(temp);
            temp.clear();
        }
        else {
            temp.insert(stoi(s));
        }

    }
    for (int i = 0; i < usull.size()-1; i++) {
        cout << '\\' << '\n';
        temp.clear();
        set_difference(usull[i].begin(), usull[i].end(), usull[i+1].begin(), usull[i+1].end(), inserter(temp, temp.begin()));
        for (auto j : temp) {
            cout << j << '\n';
        }
        cout << '/' << '\n';
    }
    return 0;
}
