#include <iostream>
#include <fstream>

using namespace std;
ofstream out("output.txt");
ifstream in("input.txt");

class Stack {
	struct Element {
		int inf;
		Element* next;
		Element(int x, Element *p) : inf(x), next(p){}
	};
	Element* head;
public:
	Stack() : head(0){}
	bool Empty() {
		return head == 0;
	}
	int Pop() {
		if (Empty()) {
			return 0;
		}
		Element* r = head;
		int i = r->inf;
		head = r->next;
		delete r;
		return i;
	}
	void Push(int data) {
		head = new Element(data, head);
	}
	int Top() {
		if (Empty()) {
			return 0;
		}
		else {
			return head->inf;
		}
	}
};
int main() {
	Stack a,b;
	int temp;
	while (in.peek() != EOF) {
		in >> temp;
		a.Push(temp);
	}
	int min = a.Top();
	while (!a.Empty()) {
		temp = a.Pop();
		b.Push(temp);
		if (temp < min) {
			min = temp;
		}
	}
	while (!b.Empty()) {
		temp = b.Pop();
		if (temp != min) {
			a.Push(temp);
		}
	}
	while (!a.Empty()) {
		temp = a.Pop();
		b.Push(temp);
	}
	while (!b.Empty()) {
		temp = b.Pop();
		cout << temp << ' ';
	}
	return 0;
}
