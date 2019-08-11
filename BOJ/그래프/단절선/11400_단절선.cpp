#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
vector<vector<int>>g;
set<p>ans;
int discovertime[100002];
int cnt = 0;

int dfs(int cur, int parent) {
	int low = cur, ret = discovertime[cur] = ++cnt;

	for (int i = 0; i < g[cur].size(); i++) {
		int next = g[cur][i];
		if (next == parent) continue;
		if (discovertime[next]) {
			ret = min(ret, discovertime[next]);
			continue;
		}
		low = dfs(next, cur);
		ret = min(ret, low);
		if (low > discovertime[cur]) {
			int s = min(cur, next);
			int e = max(cur, next);
			ans.insert({ s,e });
		}
	}
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
	dfs(1, 0);
	printf("%d\n", ans.size());
	for (auto it = ans.begin(); it != ans.end(); it++) {
		printf("%d %d\n", it->first, it->second);
	}
	return 0;
}