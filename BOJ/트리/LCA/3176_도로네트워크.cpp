#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
vector<vector<p>>g;
int INF = 1e9;
int depth[100001];
int weight[100001];
int dp[100001][22];
int maxw[100001][22];
int minw[100001][22];
int chk[100001];
int n, m, a, b, c, minans = INF, maxans = -INF;

void dfs(int cur, int dep) {
	chk[cur] = 1;
	depth[cur] = dep;
	for (int i = 0; i < g[cur].size(); i++) {
		int next = g[cur][i].first;
		int ncost = g[cur][i].second;
		if (!chk[next]) {
			dp[next][0] = cur;
			maxw[next][0] = max(maxw[next][0], ncost);
			minw[next][0] = min(minw[next][0], ncost);
			weight[next] = weight[cur] + ncost;
			dfs(next, dep + 1);
		}
	}
}
void go() {
	for (int j = 1; j < 22; j++) {
		for (int i = 1; i <= n; i++) {
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
			maxw[i][j] = max(maxw[i][j-1], maxw[dp[i][j - 1]][j - 1]);
			minw[i][j] = min(minw[i][j-1], minw[dp[i][j - 1]][j - 1]);
		}
	}
}
p LCA(int a, int b) { // aÀÇ ±íÀÌ¸¦ ´õ ±íÀº°É·Î µÒ
	minans = INF;
	maxans = -INF;
	if (depth[a] < depth[b]) swap(a, b);
	for (int i = 21; i >= 0; i--) {
		if (depth[a] - depth[b] >= (1 << i)) {
			minans = min(minans, minw[a][i]);
			maxans = max(maxans, maxw[a][i]);
			a = dp[a][i];
		}
	}
	if (a == b) {
		return { minans,maxans };
	}
	for (int i = 21; i >= 0; i--) {
		if (dp[a][i] != dp[b][i]) {
			minans = min(minans, min(minw[a][i], minw[b][i]));
			maxans = max(maxans, max(maxw[a][i], maxw[b][i]));
			a = dp[a][i]; b = dp[b][i];
		}
	}
	minans = min(minans, min(minw[a][0], minw[b][0]));
	maxans = max(maxans, max(maxw[a][0], maxw[b][0]));
	return { minans,maxans };
}
int main() {
	scanf("%d", &n);
	g.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d %d", &a, &b, &c);
		g[a].push_back({ b,c }); g[b].push_back({ a,c });
	}
	for (int i = 0; i <= n; i++) for (int j = 0; j < 22; j++) minw[i][j] = INF;
	dfs(1, 0);
	go();
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		p ans = LCA(a, b);
		printf("%d %d\n", ans.first, ans.second);
	}
	return 0;
}
