#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
vector<vector<int>>g;
int cnt = 0, svcnt = 0;
int scc[100002];
int num[100002];
int ind[100002];
stack <int> s;
int dfs(int cur) {
	int ret = num[cur] = ++cnt;
	s.push(cur);
	for (int next : g[cur]) {
		if (!num[next]) ret = min(ret, dfs(next));
		else if (!scc[next]) ret = min(ret, num[next]);
	}
	if (ret == num[cur]) {
		svcnt += 1;
		while (1) {
			scc[s.top()] = svcnt;
			if (s.top() == cur) break;
			s.pop();
		}
		s.pop();
	}
	return ret;
}
int main() {
	int t, v, e, a, b, ans = 0;
	scanf("%d", &t);
	while (t--) {
		cnt = svcnt = ans = 0;
		memset(scc, 0, sizeof(scc));
		memset(num, 0, sizeof(num));
		memset(ind, 0, sizeof(ind));
		g.clear();
		scanf("%d %d", &v, &e);
		g.resize(v + 2);
		for (int i = 0; i < e; i++) {
			scanf("%d %d", &a, &b);
			g[a].push_back(b);
		}
		for (int i = 1; i <= v; i++) if (!scc[i]) dfs(i);
		for (int i = 1; i <= v; i++) {
			for (int next : g[i]) {
				if (scc[i] == scc[next]) continue;
				else ind[scc[next]] += 1;
			}
		}
		for (int i = 0; i < svcnt; i++) if (ind[i] == 0) ans += 1;
		printf("%d\n", ans);
	}
	return 0;
}