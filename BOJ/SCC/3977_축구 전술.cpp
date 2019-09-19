#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;
int dis[100002], scc[100002], in[100002], c, d, e, f;
vector<vector<int>>g;
stack<int>st;
int dfs(int cur) {
	dis[cur] = ++c;
	st.push(cur);
	int ret = dis[cur];
	for (int next : g[cur]) {
		if (!dis[next]) ret = min(ret, dfs(next));
		else if (!scc[next]) ret = min(ret, dis[next]);
	}
	if (ret == dis[cur]) {
		d++;
		while (1) {
			int v = st.top(); st.pop();
			scc[v] = d;
			if (v == cur) break;
		}
	}
	return ret;
}
void init() {
	memset(dis, 0, sizeof(dis));
	memset(scc, 0, sizeof(scc));
	memset(in, 0, sizeof(in));
	c = d = e = f = 0;
	g.clear();
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		init();
		int n, m; cin >> n >> m;
		g.resize(n + 1);
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			g[a].push_back(b);
		}
		for (int i = 0; i < n; i++) if (!dis[i]) dfs(i);
		for (int i = 0; i < n; i++) {
			for (int j : g[i]) {
				if (scc[i] == scc[j]) continue;
				in[scc[j]] += 1;
			}
		}
		for (int i = 1; i <= d; i++) {
			if (!in[i]) { e = i; f += 1; }
		}
		if (f > 1) { cout << "Confused\n";}
		else for (int i = 0; i < n; i++) if (scc[i] == e) cout << i << "\n";
		
		cout << "\n";
	}
	return 0;
}