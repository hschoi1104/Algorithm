#include <iostream>
using namespace std;
template <typename T>
class Node {
public:
	T value;
	Node* next;

	Node() : value(0), next(nullptr) {};
	~Node() {};
};
template <typename T>
class Queue {
private:
	Node<T>* head;
	Node<T>* tail;
	int size;
public:
	Queue() :head(nullptr), tail(nullptr), size(0) {};
	~Queue() {};
	void Push(T _value) {
		Node<T>* newNode = new Node<T>;
		newNode->value = _value;
		size++;
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = tail->next;
		}
	}
	T Pop() {
		if (size == 0) return -1;
		else {
			Node<T>* ptr = head;
			T value = head->value;

			if (head == tail) {
				head = tail = nullptr;
			}
			else {
				head = head->next;
			}
			delete ptr;
			return value;
		}
	}
	bool Empty() {
		if (head == nullptr) return true;
		else return false;
	}
	T Front() {
		return head->value;
	}
};
int main() {
	Queue<int> q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	q.Push(5);
	cout << q.Pop() << "\n";
	cout << q.Pop() << "\n";
	cout << q.Pop() << "\n";
	cout << q.Pop() << "\n";
	cout << "is Empty? :" << (q.Empty() ? "yes" : "no") << "\n";
	cout << q.Pop() << "\n";
	cout << "is Empty? :" << (q.Empty() ? "yes" : "no") << "\n";
	return 0;
}