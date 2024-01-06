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
	int temp, cnt = 0, id, cnt1 = 0;
	string temp1, temp2;
	in >> temp;
	vector <music> a(temp);
	music temp3;
	while (in.peek() != EOF) {
		in >> a[cnt].Comp >> a[cnt].name;
		cnt++;
	}
	cin >> id;
	temp3.Comp = "Rock";
	temp3.name = "4";
	a.insert(a.begin()+id+1, temp3);
	temp3.Comp = "Rock";
	temp3.name = "5";
	a.insert(a.begin() + 1, temp3);
	cout << cnt << '\n';
	for (int i = 0; i < a.size(); i++) {
		a[i].print();
	}

	in.close();
	out.close();
	return 0;
}
