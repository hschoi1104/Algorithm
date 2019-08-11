#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> p;
queue<p>q;
vector<vector<p>>g;
int chk[5001];
int ans = 0;
int dfs(int cur, int usado) {
	chk[cur] = 1;
	for (int i = 0; i < g[cur].size(); i++) {
		int next = g[cur][i].first;
		int val = g[cur][i].second;
		if (chk[next] == 0 && val >= usado) {
			ans += 1;
			dfs(next, usado);
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	g.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b, c; cin >> a >> b >> c;
		g[a].push_back({ b,c }); g[b].push_back({ a,c });
	}
	for (int i = 0; i < q; i++) {
		int k, v; cin >> k >> v;
		fill(begin(chk), end(chk), 0);
		ans = 0;
		cout << dfs(v, k) << "\n";
	}
	return 0;
}