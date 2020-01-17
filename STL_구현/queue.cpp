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
class Queue {
private:
	Node<T>* head;
	Node<T>* tail;
	T size;
public:
	Queue() :head(nullptr), tail(nullptr), size(0) {};
	~Queue() {};
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
		int value = ptr->val;
		if (head == tail) head = tail = nullptr;
		else head = head->next;
		delete ptr;
		size -= 1;
		return value;
	}

	bool Empty() {
		if (!size) return true;
		else return false;
	}

	T front() {
		return head->val;
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