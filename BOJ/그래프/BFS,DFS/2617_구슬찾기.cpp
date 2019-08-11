#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
vector<vector<int>>g;
vector<vector<int>>r;
int chk[101];
int ans[101];
int rans[101];
int n, m, u, v;
void dfs(int cur) {
	chk[cur] = 1;
	for (int i = 0; i < g[cur].size(); i++) {
		int next = g[cur][i];
		if (chk[next] == 0) {
			chk[next] = 1;
			dfs(next);
		}
	}
	return;
}
void rdfs(int cur) {
	chk[cur] = 1;
	for (int i = 0; i < r[cur].size(); i++) {
		int next = r[cur][i];
		if (chk[next] == 0) {
			chk[next] = 1;
			rdfs(next);
		}
	}
	return;
}
int count() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (chk[i]) cnt += 1;
	}
	return cnt-1;
}
int main() {
	scanf("%d %d", &n, &m);
	//input
	g.resize(n + 1); r.resize(n + 1);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		g[u].push_back(v); r[v].push_back(u);
	}
	//dfs
	for (int i = 1; i <= n; i++) {
		memset(chk, 0, sizeof(chk));
		dfs(i);
		ans[i]=count();
	}
	for (int i = 1; i <= n; i++) {
		memset(chk, 0, sizeof(chk));
		rdfs(i);
		rans[i] = count();
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (ans[i] > n / 2 || rans[i] > n / 2) res += 1;
	}
	printf("%d", res);
	return 0;
}