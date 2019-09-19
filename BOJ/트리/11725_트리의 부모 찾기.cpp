#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>>g;
int par[1000002];
int chk[1000002];
void dfs(int cur) {
	chk[cur] = 1;
	for (int i = 0; i < g[cur].size(); i++) {
		int next = g[cur][i];
		if (chk[next]) continue;
		par[next] = cur;
		dfs(next);
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	g.resize(n + 1);
	for (int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b); g[b].push_back(a);
	}
	dfs(1);
	for (int i = 2; i <= n; i++) {cout << par[i] << "\n";}
	return 0;
}