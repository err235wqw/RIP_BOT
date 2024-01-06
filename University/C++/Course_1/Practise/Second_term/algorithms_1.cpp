#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;

bool naOsi(pair<int, int> point) {
    return (point.first == 0 || point.second == 0);
}

int main() {
    int cnt1 = 0, cnt2 = 0;
    vector<pair<int, int>> points = { {1, 2}, {0, 3}, {-2, 0}, {4, 4}, {5, 1}, {0, -3} };
    for (int i = 0; i < points.size(); i++) {
        if (points[i].first == 0) {
            cnt1++;
        }
    }
    points.erase(remove_if(points.begin(), points.end(), naOsi), points.end());
    cout << cnt1 << '\n';
    for (int i = 0; i < points.size(); i++) {
        if (points[i].first >  points[i].second) {
            cnt2++;
        }
    }
    cout << cnt2<<'\n';

    sort(points.begin(), points.end(), [](pair<int, int> a, pair<int, int> b) {return (a.second > b.second);});

    for (const auto& point : points) {
        cout << "(" << point.first << ", " << point.second << ") ";
    }
    cout << endl;

    return 0;
}
