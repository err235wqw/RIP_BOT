#include <iostream>
#include <fstream>
#include <list>
#include <vector>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

class sound {
public:
	int hii, lng;
	void print() {
		cout << hii << ' ' << lng << '\n';
	}
};

int main() {
	int temp, cnt = 0, id, cnt1 = 0, hii1, lng1;
	string temp1, temp2;

	list <sound> a;
	sound temp3;
	while (in.peek() != EOF) {
		in >> temp3.hii >> temp3.lng;
		a.push_back(temp3);
		cnt++;
	}
	cin >> hii1 >> lng1;

	while(!a.empty()) {
		temp3 = a.back();
		cnt--;
		if (temp3.hii == hii1 && temp3.lng == lng1) {
			a.pop_back();
			a.push_front(temp3);
			break;
		}
		a.pop_back();
		a.push_front(temp3);

	}
	while (!a.empty()) {
		temp3 = a.front();
		cout << temp3.hii << ' ' << temp3.lng << '\n';
		a.pop_front();

	}
	in.close();
	out.close();
	return 0;
}
