#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
vector<vector<int>>g;
set<int>ans;
int discovertime[10002];
int cnt = 0;

int dfs(int cur, bool root) {
	discovertime[cur] = ++cnt;
	int low = cur, child = 0, ret = discovertime[cur];

	for (int i = 0; i < g[cur].size(); i++) {
		int next = g[cur][i];
		if (discovertime[next] > 0) {
			ret = min(ret, discovertime[next]);
			continue;
		}
		child += 1;
		low = dfs(next, false);
		if (!root && low >= discovertime[cur]) ans.insert(cur);
		ret = min(ret, low);
	}

	if (root && child >= 2) ans.insert(cur);
	return ret;
}
int main() {
	int v, e, a, b;
	scanf("%d %d", &v, &e);
	g.resize(v + 1);
	for (int i = 0; i < e; i++) {
		scanf("%d %d", &a, &b);
		g[a].push_back(b); g[b].push_back(a);
	}
	for (int i = 1; i <= v; i++) {
		cnt = 0;
		if (discovertime[i] == 0) dfs(i, true);
	}
	printf("%d\n", ans.size());
	for (auto it = ans.begin(); it != ans.end(); it++) {
		printf("%d ", *it);
	}
	return 0;
}