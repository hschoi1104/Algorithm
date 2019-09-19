#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef pair<int, int> p;
vector<vector<int>>g;
int arr[10010];
p level[10002];
int indeg[10002];
int cnt = 0, ans = 0, root = 0;
void dfs(int cur, int lv) {
	if (g[cur][0] != -1) dfs(g[cur][0], lv + 1);
	arr[cur] = ++cnt;
	if (g[cur][1] != -1) dfs(g[cur][1], lv + 1);
	level[lv] = { min(level[lv].first, arr[cur]), max(level[lv].second, arr[cur]) };
	return;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	g.resize(n + 1);
	for (int i = 0; i < 10002; i++) { level[i] = { INT_MAX,0 }; }
	for (int i = 0; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		indeg[b] += 1; indeg[c] += 1;
		g[a].push_back(b); g[a].push_back(c);
	}

	for (int i = 1; i <= n; i++)
		if (indeg[i] == 0) { root = i; break; }

	dfs(root, 1);

	for (int i = 1; i <= n; i++) {
		if (level[i].first == INT_MAX) break;
		ans = max(ans, level[i].second - level[i].first + 1);
	}

	for (int i = 1; i <= n; i++) {
		if (level[i].first == INT_MAX) break;
		if (ans == level[i].second - level[i].first + 1) { cout << i << " " << ans; return 0; }
	}
	return 0;
}