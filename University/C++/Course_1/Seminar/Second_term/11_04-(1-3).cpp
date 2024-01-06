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

class BowlingBall {
    int weight;
    string color;
public:
    static int count;
    BowlingBall() {
        count++;
    } 

    BowlingBall(int weight, string color) {
        count++;
        setParams(weight, color);
    }

    BowlingBall(const BowlingBall& other) {
        setParams(other.weight, other.color);
        count++;
    }

    bool setWeight(int weight) {
        if (weight > 0) {
            this->weight = weight;
            return true;
        }
        return false;
    }
    bool setColor(string color) {
        if (color != "") {
            this->color = color;
            return true;
        }
        return false;
    }
    void setParams(int weight, string color) {
        setWeight(weight);
        setColor(color);
    }
    void print() {
        cout << weight << " (" << color << ")\n";
    }
    static bool isGreater(const BowlingBall& x, const BowlingBall& y) {
        if (x.weight != y.weight) {
            return x.weight > y.weight;
        }
        else {
            return x.color < y.color;
        }

    }

    // ++b
    BowlingBall& operator++() {
        weight++;
        return *this;
    }
    // b++
    BowlingBall operator++(int) {
        BowlingBall tmp(*this);
        weight++;
        return tmp;
    }
    // <
    bool operator<(const BowlingBall& other) const {
        return(weight < other.weight);
    }
    // ==
    bool operator==(const BowlingBall& other) const {
        return (weight == other.weight && color == other.color);
    }
};

int BowlingBall::count = 0;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    BowlingBall b(5, "white");
    cout << BowlingBall::count << '\n';
    b.print();
    b.setColor("purple");
    b.print();
    cout << BowlingBall::count << '\n';
    BowlingBall b1 = b;  // b1(b)
    b1.print();
    cout << BowlingBall::count << '\n';
    BowlingBall b2(3, "yellow");
    cout << BowlingBall::count << '\n';
    b2 = b1;
    b2.print();
    cout << BowlingBall::count << '\n' << '\n';
    //num_0
    BowlingBall a(5, "grey");
    a.print();
    BowlingBall a2 = ++a;
    a.print();
    cout << "a2 уже увеличилось на 1:" << '\n';
    a2.print();
    cout << '\n';
    BowlingBall c(5, "grey");
    c.print();
    BowlingBall c2 = c++;
    c.print();
    cout << "c2 еще не увеличилось на 1:" << '\n';
    c2.print();
    cout << '\n';
    //num_2
    cout << "Изначальные данные:" << '\n';
    cout << "d1(10, red)" << '\n';
    cout << "d2(9, orange)" << '\n';
    cout << "d3(8, yellow)" << '\n';
    cout << "d4(7, green)" << '\n';
    cout << "d5(6, blue)" << '\n';
    BowlingBall d1(10, "red");
    BowlingBall d2(9, "orange");
    BowlingBall d3(8, "yellow");
    BowlingBall d4(7, "green");
    BowlingBall d5(6, "blue");
    BowlingBall mas[5] = { d1,d2,d3,d4,d5 };
    int n = 5;
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (mas[j] < mas[j - 1]) {
                BowlingBall temp = mas[j];
                mas[j] = mas[j - 1];
                mas[j - 1] = temp;
            }
        }
    }
    cout << '\n';
    cout << "После сортировки:" << '\n';
    for (int i = 0; i < n; i++) {
        mas[i].print();
    }
    cout << '\n';
    //num_3
    BowlingBall x(1, "white");
    BowlingBall y(1, "white");
    cout << "Входные данные:" << '\n';
    cout << "x(1, white)" << '\n';
    cout << "y(1, white)" << '\n';
    cout << "is x > y?" << '\n';
    if (BowlingBall::isGreater(x, y)) {
        cout << "yes";
    }
    else
        cout << "no";
    cout << '\n';
    BowlingBall x1(1, "white");
    BowlingBall y1(1, "yellow");
    cout << "Входные данные:" << '\n';
    cout << "x1(1, white)" << '\n';
    cout << "y1(1, yellow)" << '\n';
    cout << "is x1 > y1?" << '\n';
    if (BowlingBall::isGreater(x1, y1)) {
        cout << "yes";
    }
    else
        cout << "no";
    return 0;
}
