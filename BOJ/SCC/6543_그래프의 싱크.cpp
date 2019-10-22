#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;
int dis[100002], scc[100002], out[100002], c, d, e, f;
vector<vector<int>>g, ans;
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
			ans[d].push_back(v);
			if (v == cur) break;
		}
	}
	return ret;
}
void init() {
	memset(dis, 0, sizeof(dis));
	memset(scc, 0, sizeof(scc));
	memset(out, 0, sizeof(out));
	c = d = e = f = 0;
	g.clear(); ans.clear();
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (1) {
		init();
		int n; cin >> n;
		if (n == 0) return 0;
		int m; cin >> m;
		g.resize(n + 2); ans.resize(n + 2);
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			g[a].push_back(b);
		}
		for (int i = 1; i <= n; i++) if (!dis[i]) dfs(i);
		for (int i = 1; i <= n; i++) {
			for (int j : g[i]) {
				if (scc[i] == scc[j]) continue;
				out[scc[i]] += 1;
			}
		}
		vector<int>p;
		for (int i = 1; i <= d; i++) {
			if (!out[i]) {
				for (auto it : ans[i]) {
					p.push_back(it);
				}
			}
		}
		sort(p.begin(), p.end());
		for (int i = 0; i < p.size(); i++) cout << p[i] << " ";
		cout << "\n";
	}
	return 0;
}