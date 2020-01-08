#include<iostream>
using namespace std;
template <typename T>
class Node {
public:
	T value;
	Node<T>* next = nullptr;
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
	void Push(T _value) {
		Node<T>* newNode = new Node<T>;
		newNode->value = _value;
		if (head == nullptr) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = tail->next;
		}
		size++;
	}
	T Pop() {
		if (size == 0) return -1;
		else {
			Node<T>* ptr = head;
			int value = ptr->value;
			if (head == tail) {
				head = tail = nullptr;
			}
			else {
				while (ptr != nullptr) {
					if (ptr->next == tail) break;
					ptr = ptr->next;
				}
				value = ptr->next->value;
			}
			delete tail;
			tail = ptr;
			size--;
			return value;
		}
	}
	T Top() {
		return tail->value;
	}
	T Size() {
		return size;
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