#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
queue <pair<int, int>> q;
int chk[1000001];
int main() {
	int f, s, g, u, d;
	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
	q.push({ s,0 });
	chk[s] = 1;
	while (!q.empty()) {
		int c = q.front().first;
		int p = q.front().second;
		if (c == g) {
			printf("%d", p);
			return 0;
		}
		q.pop();
		if (c + u <= f && chk[c + u] != 1) {
			q.push({ c + u,p + 1 });
			chk[c + u] = 1;
		}
		if (c - d >= 0 && chk[c - d] != 1) {
			q.push({ c - d,p + 1 });
			chk[c - d] = 1;
		}

	}
	printf("use the stairs");
	return 0;
}