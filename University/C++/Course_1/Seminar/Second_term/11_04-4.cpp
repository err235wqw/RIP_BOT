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

class ntsqr {
    int mth, x1, x2, x3, x4, y1, y2, y3, y4, a, b, s, p;
public:
    static int count;
    ntsqr() {
        count++;
    }
    ntsqr(int a, int b) {
        count++;
        int x1 = 0, y1 = 0;
        setParams(a, b, x1, y1);
    }
    ntsqr(int a, int b, int x1, int y1) {
        count++;
        setParams(a, b, x1, y1);
    }
    ntsqr(int meth, int x1, int y1, int x4, int y4) {
        count++;
        int a = x4 - x1;
        int b = y1 - y4;
        setParams(a, b, x1, y1);
    }
    void setParams(int a, int b, int x1, int y1) {
        setPoints(x1, y1, x1 + a, y1, x1, y1 - b, x1 + a, y1 - b);
        setSizes(a, b, x1, y1);

    }
    bool setPoints(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
        this->x1 = x1;
        this->x2 = x2;
        this->x3 = x3;
        this->x4 = x4;
        this->y1 = y1;
        this->y2 = y2;
        this->y3 = y3;
        this->y4 = y4;
        return 1;
    }
    bool setSizes(int a, int b, int x1, int y1) {
        this->a = a;
        this->b = b;
        this->s = a * b;
        this->p = 2 * (a + b);
        return 1;
    }
    void showInfo() {
        cout << "Длина: " << a << '\n' << "Ширина: " << b << '\n' << "Площадь: " << s << '\n' << "Периметр: " << p << '\n' <<'\n';
    }
    void showPoints() {
        cout << "1 точка: x1 = " << x1 << " y1 = " << y1 << '\n' << "2 точка: x2 = " << x2 << " y2 = " << y2 << '\n' << "3 точка: x3 = " << x3 << " y3 = " << y3 << '\n' << "4 точка: x4 = " << x4 << " y4 = " << y4 << '\n' << '\n';
    }
    int retDlin() {
        return b;
    }

    int retShir() {
        return a;
    }
    void setShir(int a) {
        setParams(a, this->b, this->x1, this->y1);
    }
    void setDlin(int b) {
        setParams(this->a, b, this->x1, this->y1);
    }
    void newFPoint(int x1, int y1) {
        setParams(this->a, this->b, x1, y1);
    }
};
int ntsqr::count = 0;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ntsqr g1(1, 0, 0, 5, -5);
    g1.showInfo();
    g1.showPoints();
    g1.newFPoint(-1, -1);
    g1.showPoints();
    g1.setDlin(30);
    g1.setShir(30);
    g1.showPoints();
    return 0;
}
