#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>>g;
int depth[100001];
int dp[100001][22];
int chk[100001];
int n, m, a, b;

void dfs(int cur, int dep) {
	chk[cur] = 1;
	depth[cur] = dep;
	for (int i = 0; i < g[cur].size(); i++) {
		int next = g[cur][i];
		if (!chk[next]) {
			dp[next][0] = cur;
			dfs(next, dep + 1);
		}
	}
}
void go() {
	for (int j = 1; j < 22; j++) for (int i = 1; i <= n; i++) dp[i][j] = dp[dp[i][j - 1]][j - 1];
}
int LCA(int a,int b) { // aÀÇ ±íÀÌ¸¦ ´õ ±íÀº°É·Î µÒ
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
	for (int i = 0; i < n-1; i++) {
		scanf("%d %d", &a, &b);
		g[a].push_back(b); g[b].push_back(a);
	}
	dfs(1, 0);
	go();
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n",LCA(a, b));
	}
	return 0;
}