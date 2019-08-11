#include <stdio.h>
#include <deque>
using namespace std;
deque<int>dq;
int main() {
	int n;
	scanf("%d", &n);
	int index = 1;
	for (int i = 1; i <= n; i++) {
		char a, b;
		int c;
		scanf(" %c %c", &a, &b);
		if (a == 'A') {
			if (b == 'L') dq.push_front(index);
			else if (b == 'R') dq.push_back(index);
			index++;
		}
		else if (a == 'D') {
			scanf("%d", &c);
			if (b == 'L')
				for (int j = 0; j < c; j++)
					dq.pop_front();
			else if (b == 'R')
				for (int j = 0; j < c; j++)
					dq.pop_back();
		}
	}
	printf("%d", dq[0]);
	for (int i = 1; i < dq.size(); i++) printf("\n%d", dq[i]);

	return 0;
}