#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    list<int> lst = { 5, 3, 1, 1, 4, 1, 1, 2 };
    auto min = min_element(lst.begin(), lst.end());
    lst.insert(min, 0);
    auto min1 = next(min, 1);
    lst.insert(min1, 0);

    for (int x : lst) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

//Время работы : O(n), где n - количество элементов в списке.Функция min_element() работает за O(n), а insert() за O(1)
