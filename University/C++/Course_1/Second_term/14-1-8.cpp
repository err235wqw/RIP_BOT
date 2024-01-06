#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <Windows.h>


using namespace std;

class mass {
	int n = 0;
	int* IntArray = new int(n);
public:
	mass() {

	}
	mass(int n) {
		SetParams(n);
	}
	mass(int n, int * a) {
		SetParams(n, a);
	}
	void SetParams(int n) {
		this->n = n;
	}
	void SetParams(int n, int * a) {
		this->n = n;
		this->IntArray = a;
	}
	void CinMass() {
		cout << "Введите количество элементов:" << '\n';
		int n;
		cin >> n;
		int* a = new int(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << "Массив введен." << '\n';
		SetParams(n, a);

	}
	void CoutMass() {
		int n = this->n;
		int* a = new int(n);
		a = this->IntArray;
		for (int i = 0; i < n; i++) {
			cout << a[i] << '\n';
		}

	}
	void Sort() {
		int n = this->n;
		int* a = new int(n);
		a = this->IntArray;
		sort(a, a + n);
		this->IntArray = a;

	}
	int Rasm() {
		return this->n;
	}
	int Sum() {
		int n = this->n;
		int* a = new int(n);
		a = this->IntArray;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i];
		}

		return sum;
	}
	int Reteil(int i) {
		return this->IntArray[i];
	}
	mass operator++() {
		for (int i = 0; i < this->n; i++) {
			this->IntArray[i]++;
		}
		return *this;
	}
	mass operator--() {
		for (int i = 0; i < this->n; i++) {
			this->IntArray[i]--;
		}
		return *this;
	}
	mass operator*(int z) {
		for (int i = 0; i < this->n; i++) {
			this->IntArray[i]= this->IntArray[i]*z;
		}
		return *this;
	}
	friend mass operator+(mass a, mass b){
		int* c = new int(a.Rasm());
		for (int i = 0; i < a.Rasm(); i++) {
			c[i] = a.Reteil(i) + b.Reteil(i);
		}
		mass z;
		z.SetParams(a.Rasm(), c);
		return z;
	}
};



int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	mass b, c, d;
	int n;
	cin >> n;
	int* a = new int(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	b.SetParams(n, a);
	b.Sort();
	b.CoutMass();
	c.CinMass();
	c.CoutMass();
	cout << "Сумма массивов" << '\n';
	d = b + c;
	d.CoutMass();
	d * 4;
	cout << "Умножение" << '\n';
	d.CoutMass();
	--b;
	cout << "--" << '\n';
	b.CoutMass();
	++c;
	cout << "++" << '\n';
	c.CoutMass();
	return 0;
}
