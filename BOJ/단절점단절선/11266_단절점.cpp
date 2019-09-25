#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int num[1000002], cnt = 0;
vector<vector<int>>g;
vector<int>ans;
int dfs(int idx, bool root) {
	int low = num[idx] = ++cnt, child = 0, c = 0, ret = cnt;
	for (int i = 0; i < g[idx].size(); i++) {
		int next = g[idx][i];
		if (!num[next]) {
			low = dfs(next, false);
			child++;
		}
		else {
			ret = min(ret, num[g[idx][i]]);
			continue;
		}
		if (!root && low >= num[idx])c = 1;

		ret = min(ret, low);
	}
	if (c || root && child > 1)  ans.push_back(idx);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int v, e; cin >> v >> e;
	g.resize(v + 1);
	for (int i = 0; i < e; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b); g[b].push_back(a);
	}
	for (int i = 1; i <= v; i++) {
		if (!num[i]) dfs(i, true);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (auto it : ans) cout << it << " ";
	return 0;
}