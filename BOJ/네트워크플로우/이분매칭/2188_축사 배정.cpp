#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
vector<vector<int>>g;
int b[202];
int chk[202];
int n, m, ans = 0;
int dfs(int cur) {
	if (chk[cur] == 1) return 0;
	chk[cur] = 1;
	for (int i = 0; i < g[cur].size(); i++) {
		int next = g[cur][i];
		if (b[next] == 0 || dfs(b[next]) == 1) {
			b[next] = cur;
			return 1;
		}
	}
	return 0;
}
int main() {
	scanf("%d %d", &n, &m);
	g.resize(n + 1);
	for (int i = 0; i < n; i++) {
		int c, x;
		scanf("%d", &c);
		for (int j = 0; j < c; j++) {
			scanf("%d", &x);
			g[i + 1].push_back(x);
		}
	}
	for (int i = 1; i <= n; i++) {
		memset(chk, 0, sizeof(chk));
		if (dfs(i) == 1) ans += 1;
	}
	printf("%d", ans);
	return 0;
}