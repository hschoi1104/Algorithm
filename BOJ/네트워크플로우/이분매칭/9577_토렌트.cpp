#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
vector<vector<int>>g;
int chk[101];
int b[101];
int t, n, m, t1, t2, a, q, maxtime = 0;


int dfs(int cur) {
	if (chk[cur]) return 0;
	chk[cur] = 1;
	for (int i = 0; i < g[cur].size(); i++) {
		int next = g[cur][i];
		if (b[next] == -1 || dfs(b[next])) {
			b[next] = cur;
			return 1;
		}
	}
	return 0;
}


int main() {
	scanf("%d", &t);
	while (t--) {
		maxtime = 0;
		g.resize(101);
		memset(chk, 0, sizeof(chk));
		memset(b, -1, sizeof(b));
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &t1, &t2, &a);
			for (int j = 0; j < a; j++) {
				scanf("%d", &q);
				for (int k = t1; k < t2; k++) {
					g[k].push_back(q);
				}
			}
			maxtime = max(maxtime, t2-1);
		}
		int ans = 0; bool flag = false;
		for (int i = 0; i <= maxtime; i++) {
			memset(chk, 0, sizeof(chk));
			if (dfs(i)) ans += 1;
			if (ans == n) {
				printf("%d\n", i+1);
				flag = true;
				break;
			}
		}
		if (flag == false)printf("-1\n");
		g.clear();
	}
	return 0;
}