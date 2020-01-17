#include <iostream>
using namespace std;
template <typename T>
class Node {
public:
	T val;
	Node<T>* next;
	Node() {};
	~Node() {};
};
template <typename T>
class Stack {
private:
	Node<T>* head;
	Node<T>* tail;
	int size;
public:
	Stack() : head(nullptr), tail(nullptr), size(0) {};
	~Stack() {};
	void Push(T _val) {
		Node<T>* newNode = new Node<T>;
		newNode->val = _val;
		if (head == nullptr) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = tail->next;
		}
		size += 1;
	}
	T Pop() {
		if (!size) return -1;
		Node<T>* ptr = head;
		T value = ptr->val;
		if (head == tail) {
			delete tail;
			head = tail = nullptr;
		}
		else {
			while (ptr->next != tail) {
				ptr = ptr->next;
			}
			value = ptr->next->val;
			delete tail;
			tail = ptr;
		}
		size--;
		return value;
	}
	bool Empty() {
		if (!size) return true;
		else return false;
	}
	T Size() {
		return size;
	}
	T Top() {
		return tail->val;
	}
};
int main() {
	Stack<int> s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	s.Push(5);
	cout << "TOP: " << s.Top() << "\n";
	cout << s.Pop() << "\n";
	cout << "TOP: " << s.Top() << "\n";
	cout << s.Pop() << "\n";
	cout << "TOP: " << s.Top() << "\n";
	cout << s.Pop() << "\n";
	cout << "TOP: " << s.Top() << "\n";
	cout << s.Pop() << "\n";
	cout << "TOP: " << s.Top() << "\n";
	cout << s.Pop() << "\n";
}