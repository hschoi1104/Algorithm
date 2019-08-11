#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> p;
queue<p>q;
vector<int>v;
int main() {
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < ((1 << n)-1); i++) {
		scanf("%d", &x);
		v.push_back(x);
	}
	q.push({ 0,(1 << n) - 2 });
	while (!q.empty()) {
		int cur = q.size();
		for (int i = 0; i < cur; i++) {
			int s = q.front().first;
			int e = q.front().second;
			q.pop();
			printf("%d ", v[(s + e) / 2]);
			if (s == e) continue;
			if (s <= (s + e) / 2 - 1) q.push({ s,(s + e) / 2 - 1 });
			if ((s + e) / 2 + 1 <= e) q.push({ (s + e) / 2 + 1, e });
		}
		printf("\n");
	}
	return 0;
}