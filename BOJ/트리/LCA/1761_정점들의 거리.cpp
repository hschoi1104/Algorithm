#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
vector<vector<p>>g;
int depth[40001];
int weight[40001];
int dp[40001][22];
int chk[40001];
int n, m, a, b, c;

void dfs(int cur, int dep) {
	chk[cur] = 1;
	depth[cur] = dep;
	for (int i = 0; i < g[cur].size(); i++) {
		int next = g[cur][i].first;
		int ncost = g[cur][i].second;
		if (!chk[next]) {
			dp[next][0] = cur;
			weight[next] = weight[cur] + ncost;
			dfs(next, dep + 1);
		}
	}
}
void go() {
	for (int j = 1; j < 22; j++) for (int i = 1; i <= n; i++) dp[i][j] = dp[dp[i][j - 1]][j - 1];
}
int LCA(int a, int b) { // aÀÇ ±íÀÌ¸¦ ´õ ±íÀº°É·Î µÒ
	if (depth[a] < depth[b]) swap(a, b);
	for (int i = 21; i >= 0; i--) {
		if (depth[a] - depth[b] >= (1 << i)) a = dp[a][i];
	}
	if (a == b) return a;
	for (int i = 21; i >= 0; i--) {
		if (dp[a][i] != dp[b][i]) {
			a = dp[a][i]; b = dp[b][i];
		}
	}
	return dp[a][0];
}
int main() {
	scanf("%d", &n);
	g.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d %d", &a, &b, &c);
		g[a].push_back({ b,c }); g[b].push_back({ a,c });
	}
	dfs(1, 0);
	go();
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		int p = LCA(a, b);
		printf("%d\n", weight[a] + weight[b] - 2 * weight[p]);
	}
	return 0;
}