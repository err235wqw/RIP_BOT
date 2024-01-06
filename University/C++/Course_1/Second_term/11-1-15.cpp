#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

struct stud {
	int year,p1,p2,p3,p4,p5;
	string name,surrname,secname;
};

void bubblesrt(stud* a, int n) {
	stud temp;
	int i, j;
	for(i= 0; i < n-1; i++)
		for (j = n - 1; j > i; j--) {
			bool fl = 0;
				for (int i1 = 0; i1 < min(a[j].surrname.size(), a[j - 1].surrname.size()); i1++)
					if (a[j].surrname[i1] < a[j - 1].surrname[i1]) {
						fl = 1;
					}
					else {
						if (a[j].surrname[i1] == a[j - 1].surrname[i1])
							continue;
						else
							break;
					}
				if (fl) {
					swap(a[j], a[j - 1]);
				}
		}
		for (i = 0; i < n - 1; i++)
			for (j = n - 1; j > i; j--)
				if (a[j].year < a[j - 1].year && a[j].surrname == a[j - 1].surrname) {
					swap(a[j], a[j - 1]);
				}
			
}
void vybsort(stud * mas1, int n) {
	for (int i = 0; i < n - 1; i++) {
		int mind = i;
		for (int j = i + 1; j < n; j++) {
			if (mas1[j].surrname < mas1[mind].surrname) {
				mind = j;
			}
			else if (mas1[j].surrname == mas1[mind].surrname && mas1[j].year > mas1[mind].year) {
				mind = j;
			}
		}
		if (mind != i) {
			swap(mas1[i], mas1[mind]);
		}
	}
}

void vstsort(stud* mas2, int n) {
	for (int i = 1; i < n; i++) {
		stud key = mas2[i];
		int j = i - 1;
		while (j >= 0 && (mas2[j].surrname > key.surrname || (mas2[j].surrname == key.surrname && mas2[j].year < key.year))) {
			mas2[j + 1] = mas2[j];
			j = j - 1;
		}
		mas2[j + 1] = key;
	}
}


ifstream in("input.txt");
ofstream out("output.txt");

int main() {

	int num, n = 0;
	string ss;
	while (in >> ss) {
		n++;
	}
	n = (n - 1) / 9 + 1;
	in.clear();
	in.seekg(0);
	in >> num;
	stud * a = new stud[n];
	for (int i = 0; i < n-1; i++) {
		in >> a[i].name >> a[i].surrname >> a[i].secname >> a[i].year >> a[i].p1 >> a[i].p2 >> a[i].p3 >> a[i].p4 >> a[i].p5;


	}
	bubblesrt(a, n-1);
	//vstsort(a, n - 1);
	//vybsort(a, n - 1);
	out << num << '\n';
	for (int i = 0; i < n-1; i++) {
		out << a[i].name << ' ' << a[i].surrname << ' ' << a[i].secname << ' ' << a[i].year << ' ' << a[i].p1 << ' ' << a[i].p2 << ' ' << a[i].p3 << ' ' << a[i].p4 << ' ' << a[i].p5 << '\n';
	}
	in.close();
	out.close();
	return 0;
}
