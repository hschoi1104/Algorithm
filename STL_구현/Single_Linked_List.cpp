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
class SLL {
private:
	Node<T>* head;
	Node<T>* tail;
	T size;
public:
	SLL() :head(nullptr), tail(nullptr), size(0) {};
	~SLL() {};
	void AddNode(T _val) {
		Node<T>* newNode = new Node<T>;
		newNode->val = _val;
		newNode->next = nullptr;
		if (head == nullptr) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = tail->next;
		}
		size++;
	}
	bool Find(T _val) {
		Node<T>* ptr = head;
		if (!size) return false;
		while (ptr != nullptr) {
			if (ptr->val == _val) return true;
			ptr = ptr->next;
		}
		return false;
	}
	void DeleteNode(T _val) {
		Node<T>* ptr = head;
		Node<T>* tmp = ptr;
		if (!size) return;
		if (size == 1) {
			delete ptr;
			head = tail = nullptr;
			size = 0;
			return;
		}
		while (ptr!= nullptr) {
			if (ptr->val == _val) break;
			tmp = ptr;
			ptr = ptr->next;
		}
		tmp->next = ptr->next;
		delete ptr;
		size--;
	}
	void Print() {
		Node<T>* ptr = head;
		while (ptr != nullptr) {
			cout << ptr->val << " ";
			ptr = ptr->next;
		}
		cout << "\n";
		return;
	}
	void AddPos(T _pos, T _val) {
		if (_pos > size) return;
		Node<T>* newNode = new Node<T>;
		newNode->val = _val;
		newNode->next = nullptr;
		Node<T>* ptr = head;
		Node<T>* tmp = ptr;
		for (int i = 0; i < _pos; i++) {
			tmp = ptr;
			ptr = ptr->next;
		}
		tmp->next = newNode;
		newNode->next = ptr;
		size++;
	}
};
int main() {
	SLL<int> sll;
	sll.AddNode(1);
	sll.AddNode(2);
	sll.AddNode(3);
	sll.AddNode(4);
	sll.AddNode(5);
	sll.AddNode(6);
	sll.Print();
	sll.DeleteNode(3);
	sll.Print();
	//cout << (sll.Find(2)) << "\n";
	sll.DeleteNode(2);
	sll.Print();
	sll.DeleteNode(4);
	sll.Print();
	sll.DeleteNode(5);
	sll.Print();
	sll.DeleteNode(6);
	sll.Print();
	sll.DeleteNode(1);
	sll.Print();
	return 0;
}