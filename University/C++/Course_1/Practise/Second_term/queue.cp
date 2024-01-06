#include <iostream>
#include <fstream>

using namespace std;
ofstream out("output.txt");
ifstream in("input.txt");

template <class Item> class Queue {
	struct Element {
		Item inf;
		Element* next;
		Element(Item x) : inf(x), next(0){}
	};
	Element* head, *tail;
public:
	Queue() : head(0), tail(0){}
	bool Empty() {
		return head == 0;
	}
	int Pop() {
		if (Empty()) {
			cout << "warning koroche" << '\n';
		}
		else {
			Element* t = head;
			int i = t->inf;
			head = t->next;
			if (head == NULL) {
				tail = NULL;
			}
			delete t;
			return i;
		}
	}
	void Put(Item data) {
		Element* t = tail;
		tail = new Element(data);
		if (!head) {
			head = tail;
		}
		else {
			t->next = tail;
		}
	}
};
int main() {
	Queue <int> a;
	int temp, cnt = 0, cnt1;
	while (in.peek() != EOF) {
		in >> temp;
		cnt++;
		a.Put(temp);
	}
	cnt1 = cnt;
	int min = 10000;
	while (cnt1) {
		temp = a.Pop();
		a.Put(temp);
		if (temp < min) {
			min = temp;
		}
		cnt1--;
	}
	cnt1 = cnt;
	while (cnt1) {
		temp = a.Pop();
		if (temp != min) {
			a.Put(temp);
		}
		cnt1--;
	}
	while (!a.Empty()) {
		temp = a.Pop();
		cout << temp << ' ';
	}
	return 0;
}
