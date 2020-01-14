#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
	T value;
	Node* left;
	Node* right;
	Node() :value(0), left(nullptr), right(nullptr) {};
	~Node() {};
};
template <typename T>
class BST {
private:
	Node<T>* root;
	Node<T>* removeProcFindTarget(T _value) {
		Node<T>* ptr = root;
		if (ptr->value == _value) return ptr;
		else {
			while (ptr != nullptr) {
				if (ptr->value == _value) return ptr;
				else if (ptr->value > _value) ptr = ptr->left;
				else if (ptr->value < _value) ptr = ptr->right;
			}
		}
	}
	Node<T>* removeProcFindMaxVal(Node<T>* cur) {
		Node<T>* ptr = cur;
		while (ptr != nullptr) {
			if (ptr->right == nullptr) break;
			ptr = ptr->right;
		}
		return ptr;
	}
public:
	BST() :root(nullptr) {};
	~BST() {};
	void AddNode(T _value) {
		Node<T>* newNode = new Node<T>;
		Node<T>* tmp = new Node<T>;
		newNode->value = _value;
		if (root == nullptr) root = newNode;
		else {
			Node<T>* ptr = root;
			while (ptr != nullptr) {
				tmp = ptr;
				if (ptr->value < _value) ptr = ptr->right;
				else if (ptr->value > _value) ptr = ptr->left;
			}
			if (tmp->value > _value) tmp->left = newNode;
			else tmp->right = newNode;
		}
	}
	void RemoveNode(Node<T>* ptr,T _value) {
		if (ptr == nullptr) return ptr;
		else if (ptr->value > _value) ptr->left = RemoveNode(ptr->left, _value);
		else if (ptr->value < _value) ptr->right = RemoveNode(ptr->right, _value);
		else {
			//have two child
			if (ptr->left != nullptr && ptr->right != nullptr) {
				Node<T>* tmp = removeProcFindMaxVal(ptr->left);
				ptr->value = tmp->value;
				ptr->left = RemoveNode(ptr->left, tmp->value);
			}
			//leaf Node
			else if (ptr->left == nullptr && ptr->right == nullptr) {
				delete ptr;
				ptr = nullptr;
			}
			//have one child
			else if (ptr->left != nullptr) ptr = ptr->left;
			else if (ptr->right != nullptr) ptr = ptr->right;
		}
		return ptr;
	}
	bool Search(T _value) {
		Node<T>* ptr = root;
		if (ptr->value == _value) return true;
		else {
			while (ptr != nullptr) {
				if (ptr->value == _value) break;
				else if (ptr->value > _value) ptr = ptr->left;
				else if (ptr->value < _value) ptr = ptr->right;
			}
			return ptr == nullptr ? true : false;
		}
	}
	void Inorder(Node<T>* pos) {
		if (pos != nullptr) {
			Inorder(pos->left);
			cout << pos->value << " ";
			Inorder(pos->right);
		}
	}
	void showTree() {
		Inorder(root);
		cout << "\n";
	}
};
int main() {
	BST<int> bst;
	bst.AddNode(4);
	bst.showTree();
	bst.AddNode(5);
	bst.showTree();
	bst.AddNode(6);
	bst.showTree();
	bst.AddNode(1);
	bst.showTree();
	bst.AddNode(2);
	bst.showTree();
	bst.AddNode(3);
	bst.showTree();
	bst.AddNode(10);
	bst.AddNode(20);
	bst.AddNode(30);
	bst.showTree();
	
}