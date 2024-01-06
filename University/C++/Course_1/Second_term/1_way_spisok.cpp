#include <iostream>
#include <fstream>

using namespace std;
ofstream out("output.txt");
ifstream in("input.txt");
template <class Item> class List
{
	struct Element {
		Item value;
		Element* next;
		Element(Item x) : value(x), next(0) {}
	};
	Element* head;
	int size;
	Element* Find(int index) {
		if ((index < 1) || (index > size)) {
			return NULL;
		}
		else {
			Element* cur = head;
			for (int i = 1; i < index; i++) {
				cur = cur->next;
			}
			return cur;
		}
	}
public:
	List() : head(0), size(0) {}
	~List() {
		while (!Empty()) {
			Remove(1);
		}
	}
	bool Empty() {
		return head == 0;
	}
	int GetLength() {
		return size;
	}
	Item Get(int index) {
		if ((index < 1) || (index > size)) {
			cout << "ListException: get - list error";
		}
		else {
			Element* r = Find(index);
			Item i = r->value;
			return i;
		}
	}
	void Insert(int index, Item data) {
		if ((index < 1) || (index > size + 1)) {
			if (this->size == 0) {
				Element* newPtr = new Element(data);
				head = newPtr;
				size++;
			}
			else {
				cout << "ListException: insert - list error";
			}
		}
		else {
			Element* newPtr = new Element(data);
			size++;
			if (index == 1) {
				newPtr->next = head;
				head = newPtr;
			}
			else {
				Element* prev = Find(index - 1);
				newPtr->next = prev->next;
				prev->next = newPtr;
			}
		}
	}
	void Remove(int index) {
		if ((index < 1) || (index > size)) {
			cout << "ListException: remove - list error";
		}
		else {
			Element* cur;
			--size;
			if (index == 1) {
				cur = head;
				head = head->next;
			}
			else {
				Element* prev = Find(index - 1);
				cur = prev->next;
				prev->next = cur->next;
			}
			cur->next = NULL;
			delete cur;
		}
	}
	void Print() {
		for (Element* cur = head; cur != NULL; cur = cur->next) {
			out << cur->value << ' ';
		}
		out << '\n';
	}
	Item min_in_List() {
		Item min = head->value;
		for (Element* cur = head; cur != NULL; cur = cur->next) {
			if (cur->value < min) {
				min = cur->value;
			}
		}
		return min;
	}
	void func(int min) {
		Element* prev = head;
		for (Element* cur = prev; cur != NULL; cur = cur->next) {
			if (cur->value == min) {
				prev->next = cur->next;
			}
			else {
				prev = cur;
			}
		}
	}
};

int main() {
	List<int> a;
	int temp;
	while (in.peek() != EOF) {
		in >> temp;
		a.Insert(a.GetLength(), temp);
	}
	a.func(a.min_in_List());
	a.Print();
	return 0;
}
