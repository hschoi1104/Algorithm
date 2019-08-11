#include <iostream>
#include <queue>
using namespace std;
deque<int>dq;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = n; i > 0; i--) {
		dq.push_back(i);
	}
	while (!dq.empty()) {
		if (dq.size() == 1) {
			printf("%d", dq.front());
			break;
		}
		printf("%d ", dq.back());
		dq.pop_back();
		dq.push_front(dq.back());
		dq.pop_back();
	}

	return 0;
}