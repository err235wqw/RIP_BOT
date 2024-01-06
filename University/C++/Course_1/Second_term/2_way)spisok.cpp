#include <iostream>
#include <fstream>

using namespace std;
ofstream out("output.txt");
ifstream in("input.txt");
template <class Item> class DoubleLinkedList
{
	struct Element {
		Item value;
		Element* next;
		Element* prev;
		Element(Item x) : value(x), next(0),prev(0) {}
	};
	Element* head;
	Element *tail;
	int size;
	Element* Find(int index) {
		if ((index < 1) || (index > size-1)) {
			return NULL;
		}
		else {
			Element* curr = head;
			for (int i = 1; i < index; i++) {
				curr = curr->next;
			}
			return curr;
		}
	}
public:
	DoubleLinkedList() : head(0), tail(0), size(0) {}
	~DoubleLinkedList() {
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
			cout << "DoubleLinkedListException: get - list error";
		}
		else {
			Element* r = Find(index);
			Item i = r->value;
			return i;
		}
	}
	void InsertLeft(int index, Item data) {
		if ((index < 1) || (index > size + 1)) {
			cout << "DoubleLinkedListException: insert - list error";
		}
		else {
			Element* newPtr = new Element(data);
			size++;
			Element* cur = Find(index);
			if (cur == NULL) {
				head = newPtr;
				tail = newPtr;
			}
			else {
				newPtr->next = cur;
				newPtr->prev = cur->prev;
				cur->prev = newPtr;
				if (cur == head) {
					head = newPtr;
				}
				else {
					newPtr->prev->next = newPtr;
				}
			}
		}
	}
	void InsertRight(int index, Item data) {
		if (((index < 1)&& head != NULL) || (index > size + 1)) {
			cout << "DoubleLinkedListException: insert - list error";
		}
		else {
			Element* newPtr = new Element(data);
			size++;
			Element* cur = Find(index);
			if (cur == NULL) {
				head = newPtr;
				tail = newPtr;
			}
			else {
				newPtr->next = cur->next;
				newPtr->prev = cur;
				cur->next = newPtr;
				if (cur == tail) {
					tail = newPtr;
				}
				else {
					newPtr->next->prev = newPtr;
				}
			}
		}
	}
	void Remove(int index) {
		if ((index < 1) || (index > size)) {
			cout << "ListException: remove - list error";
		}
		else {
			Element* cur = Find(index);
			--size;
			if (size == 0) {
				head = NULL;
				tail = NULL;
			}
			else if (cur == head) {
				head = head->next;
				head->prev = NULL;
			}
			else if (cur == tail) {
				tail = tail->prev;
				tail->next = NULL;
			}
			else {
				cur->prev->next = cur->next;
				cur->next->prev = cur->prev;
			}
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
		for (int i = 1; i < size; i++) {
			Element *cur = Find(i);
			if (cur->value == min) {
				Remove(i);
				i--;
			}
		}
	}
};

int main() {
	DoubleLinkedList <int> a;
	int temp;
	while (in.peek() != EOF) {
		in >> temp;
		a.InsertRight(a.GetLength(), temp);
	}
	a.func(a.min_in_List());
	a.Print();
	return 0;
}
