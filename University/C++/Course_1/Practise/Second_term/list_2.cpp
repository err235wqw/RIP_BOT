#include <iostream>
#include <fstream>
#include <list>
#include <vector>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

class music {
public:
	string Comp, name;
	void print() {
		cout << Comp << ' ' << name << '\n';
	}
};

int main() {
	int temp, cnt = 0, id = 0, cnt1 = 0;
	string temp1, temp2;
	in >> temp;
	list <music> a, b;
	music temp3;
	while (in.peek() != EOF) {
		in >> temp1 >> temp2;
		temp3.Comp = temp1;
		temp3.name = temp2;
		a.push_back(temp3);
	}
	bool fl = 1;
	while (!a.empty()) {
		temp3 = a.back();
		if (temp3.Comp == "Rock") {
			cnt++;
			if (fl) {
				fl = 0;

			}
			else {
				b.push_back(temp3);
			}
		}
		else {
			b.push_back(temp3);
		}
		a.pop_back();

	}
	while (!b.empty()) {
		temp3 = b.back();
		cout << temp3.Comp << ' ' << temp3.name << '\n';
		b.pop_back();

	}

	cout << cnt;
	in.close();
	out.close();
	return 0;
}
