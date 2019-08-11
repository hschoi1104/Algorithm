#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
vector<vector<int>>g;
bool chk[1001];
int b[1001];
int n, k, u, v, ans = 0;

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
	scanf("%d %d", &n, &k);
	g.resize(2 * (n + 1));
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &u, &v);
		g[u].push_back(v + 500);
	}
	for (int i = 1; i <= n; i++) {
		memset(chk, 0, sizeof(chk));
		if (dfs(i))ans += 1;
	}
	printf("%d\n", ans);
	return 0;
}
