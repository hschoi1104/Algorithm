#include <iostream>
using namespace std;

template <typename T>
struct Node {
public:
	T value;
	struct Node<T>* next = nullptr;
};

template <typename T>
class SLL {
private:
	Node<T>* head;
	Node<T>* tail;
	int size = 0;
public:
	SLL() : head(nullptr), tail(nullptr) {}
	~SLL() {}

	void addNode(T _value) {
		Node<T>* node = new Node<T>;
		size++;
		node->value = _value;
		node->next = nullptr;

		if (head == nullptr) {
			head = node;
			tail = node;
		}
		else {
			tail->next = node;
			tail = tail->next;
		}
	}
	void removeNode(T _value) {
		Node<T>* ptr = head;
		Node<T>* tmp = ptr;
		while (ptr != nullptr) {
			if (ptr->value == _value) {
				break;
			}
			else {
				tmp = ptr;
				ptr = tmp->next;
			}
		}
		if (ptr != nullptr) {
			cout << "delete:" << ptr->value << "\n";
			tmp->next = ptr->next;
			delete ptr;
			size--;
		}
		else {
			cout << "delete fail\n";
		}
	}

	void show() {
		Node<T>* ptr = head;
		while (ptr != nullptr) {
			cout << ptr->value << " ";
			ptr = ptr->next;
		}
		cout << "\n";
	}
	void deleteList() {
		Node<T>* ptr = head;
		while (ptr != nullptr) {
			head = ptr->next;
			delete ptr;
			ptr = head;
		}
		size = 0;
	}
	void addPos(int _index, int _value) {
		Node<T>* node = new Node<T>;
		Node<T>* ptr = head;
		Node<T>* tmp = ptr;

		node->value = _value;
		node->next = nullptr;
		for (int i = 0; i < _index; i++) {
			tmp = ptr;
			ptr = ptr->next;
		}
		tmp->next = node;
		node->next = ptr;
		size++;
	}
	void search(int _value) {
		Node<T>* ptr = head;
		int index = 0;
		while (ptr != nullptr) {
			if (ptr->value == _value) {
				cout << index << "번째 존재\n";
				break;
			}
			ptr = ptr->next;
			index++;
		}
	}
	int Size() {
		return size;
	}
};
int main() {
	SLL<int> sll;
	sll.addNode(1);
	sll.addNode(2);
	sll.addNode(3);
	sll.addNode(5);
	sll.addNode(6);
	sll.show();
	sll.addPos(3, 4);
	sll.show();
	sll.removeNode(2);
	sll.show();
	sll.deleteList();
	sll.show();
	return 0;
}