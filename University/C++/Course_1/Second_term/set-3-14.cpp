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
    set <set<string>> dz;
    set <char> tz;
    set<string> asksl;
    set<string> usull;
    set<string> voids;
    set<string> temp;
    string s;

    while (fin.peek() != EOF) {
        fin >> s;
        if (*s.rbegin() == '.') {
            s.pop_back();
            temp.insert(s);
            usull.insert(temp.begin(),temp.end());
            temp.clear();
        }
        else {
            if (*s.rbegin() == ',') {
                s.pop_back();
                temp.insert(s);
            }
            else {
                if (*s.rbegin() == '!') {
                    s.pop_back();
                    temp.insert(s);
                    voids.insert(temp.begin(), temp.end());
                    temp.clear();
                }
                else {
                    if (*s.rbegin() == '?') {
                        s.pop_back();
                        temp.insert(s);
                        asksl.insert(temp.begin(),temp.end());
                        temp.clear();

                    }
                    else {
                        temp.insert(s);
                    }
                }
            }
        }
    }
    set_intersection(asksl.begin(),asksl.end(),voids.begin(),voids.end(),inserter(temp,temp.begin()));
    for (auto i : temp) {
        cout << i << '\n';
    }
    return 0;
}
