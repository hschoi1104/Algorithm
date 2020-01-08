#include <iostream>
using namespace std;
template <typename T>
class Node {
public:
	T value;
	Node<T>* next;
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
	T Pop() {
		if (size == 0) return -1;
		size--;
		Node<T>* ptr = head;
		T value = ptr->value;
		if (head == tail) {
			head = tail = nullptr;
		}
		else {
			head = head->next;
		}
		delete ptr;
		return value;
	}
	T Front() {
		return head->value;
	}
	bool Empty() {
		if (size == 0) return 1;
		else return 0;
	}
};
int arr[101][2];
int chk[101];
Queue<int>q;
void init() {
	while (!q.Empty()) {
		q.Pop();
	}
	for (int i = 0; i < 101; i++) {
		arr[i][0] = arr[i][1] = chk[i] = 0;
	}
}
int bfs() {
	q.Push(1);
	chk[1] = 1;
	while (!q.Empty()) {
		int cur = q.Front();
		q.Pop();
		for (int i = 0; i < 2; i++) {
			if (arr[cur][i] != 0) {
				int next = arr[cur][i];
				if (chk[next] == 0) {
					q.Push(next);
					chk[next] = 1;
				}
			}
		}
	}
	if (chk[100]) return 1;
	else return 0;
}
int main() {
	int tt = 10;
	for (int t = 1; t <= tt; t++) {
		int n, m; cin >> n >> m;
		init();
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			if (arr[a + 1][0] == 0) arr[a + 1][0] = b + 1;
			else arr[a + 1][1] = b + 1;
		}
		cout << "#" << t << " " << bfs() << "\n";
	}
	return 0;
}