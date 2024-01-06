#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
    list<int> a = { 12, 34, 56, 78, 90 };

    auto lastTwo = prev(a.end(), 2);
    auto minElement = min_element(lastTwo, a.end());
    a.erase(minElement);

    for (int num : a) {
        cout << num << " ";
    }

    return 0;
}
