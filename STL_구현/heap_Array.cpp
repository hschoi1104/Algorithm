#include <iostream>
using namespace std;

template <typename T>
class Heap {
private:
	int size;
	T* heap;

	void push_process(int pos) {
		if (pos == 1) return;
		int par = pos / 2;
		if (heap[par] < heap[pos]) {
			T tmp = heap[par];
			heap[par] = heap[pos];
			heap[pos] = tmp;
			push_process(par);
		}
	}
	void pop_process(int pos) {
		T left = (pos * 2 <= size) ? pos * 2 : -1;
		T right = (pos * 2 + 1 <= size) ? pos * 2 + 1 : -1;
		T target = 0;
		if (left == -1 && right == -1) return;
		else if (left == -1 || right == -1)target = left;
		else target = (heap[left] > heap[right]) ? left : right;

		if (heap[target] > heap[pos]) {
			T tmp = heap[target];
			heap[target] = heap[pos];
			heap[pos] = tmp;
			pop_process(target);
		}
	}
public:
	Heap(T n) {
		size = 0;
		heap = new T[n + 1];
	}
	~Heap() {
		delete[] heap;
	}
	void Push(int _value) {
		heap[++size] = _value;
		push_process(size);
	}
	void Pop() {
		if (!size) return;
		heap[1] = heap[size--];
		pop_process(1);
	}
	T Top() {
		return (size) ? heap[1] : -1;
	}
	bool Empty() {
		return !size;
	}
	T Size() {
		return size;
	}
};
int main() {
	Heap<int> pq(30);
	pq.Push(1); cout << pq.Top()<<"\n";
	pq.Push(2); cout << pq.Top() << "\n";
	pq.Push(3); cout << pq.Top() << "\n";
	pq.Push(4); cout << pq.Top() << "\n";
	pq.Push(5); cout << pq.Top() << "\n";
	pq.Push(6); cout << pq.Top() << "\n";

	pq.Pop(); cout << pq.Top() << "\n";
	pq.Pop(); cout << pq.Top() << "\n";

	return 0;
}