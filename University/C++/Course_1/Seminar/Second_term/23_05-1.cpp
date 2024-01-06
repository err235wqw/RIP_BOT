#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector <int> vec = { 5, 3, 0, 1, 4, 0, 1, 2 };

    auto min = min_element(vec.begin(), vec.end());
    auto min1 = next(min, 2);
    vec.insert(min, 0);
    vec.insert(min1, 0);

    for (auto x : vec) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

//Время работы : O(n), где n - количество элементов в векторе.Функция min_element() работает за O(n), а insert() за O(n)
