#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string.h>
using namespace std;
vector<vector<int>>g, rg, ans;
stack<int>s;
int chk[100002], scc[100002], in[100002], cnt = 0, c = 0;
void init() {
	g.clear();
	rg.clear();
	ans.clear();
	memset(chk, 0, sizeof(chk));
	memset(scc, 0, sizeof(scc));
	memset(in, 0, sizeof(in));
	cnt = 0;
	c = 0;
}
void dfs(int cur) {
	chk[cur] = 1;
	for (int i = 0; i < g[cur].size(); i++) {
		int next = g[cur][i];
		if (chk[next]) continue;
		dfs(next);
	}
	s.push(cur);
	return;
}
void Kosaraju(int cur, int cnt) {
	chk[cur] = 1;
	scc[cur] = cnt;
	for (int i = 0; i < rg[cur].size(); i++) {
		int next = rg[cur][i];
		if (chk[next])continue;
		Kosaraju(next, cnt);
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		init();
		int n, e; cin >> n >> e;
		g.resize(n + 1); ans.resize(n + 1); rg.resize(n + 1);
		for (int i = 0; i < e; i++) {
			int a, b; cin >> a >> b;
			g[a].push_back(b);
			rg[b].push_back(a);
		}
		for (int i = 1; i <= n; i++) if (!chk[i]) dfs(i);
		memset(chk, 0, sizeof(chk));
		while (!s.empty()) {
			int p = s.top(); s.pop();
			if (!chk[p]) Kosaraju(p, ++cnt);
		}
		for (int i = 1; i <= n; i++) {
			for (int j : g[i]) {
				if (scc[i] != scc[j]) in[scc[j]] += 1;
			}
		}
		for (int i = 1; i <= cnt; i++) if (!in[i]) c += 1;
		cout << c << "\n";
	}
	return 0;
}