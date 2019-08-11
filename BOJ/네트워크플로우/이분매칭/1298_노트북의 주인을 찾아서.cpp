#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
vector<vector<int>>g;
int b[5110];
int chk[101];
int ans = 0;
int dfs(int cur) {
	if (chk[cur]) return 0;
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
	int n, m, u, v;
	g.resize(5110);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		g[u].push_back(v+100);
	}
	for (int i = 1; i <= n; i++) {
		memset(chk, 0, sizeof(chk));
		ans += dfs(i);
	}
	printf("%d", ans);
	return 0;
}