#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#include <string.h>
using namespace std;
int INF = 999999999;
typedef pair<int, int> p;
vector<vector<p>>g;
int dist[1001];
int path[1001];
vector<p>ans;
int n, m;
void dijstra() {
	priority_queue<p, vector<p>, greater<p>> pq;
	for (int i = 2; i <= n; i++) {
		pq.push({ INF,i });
		dist[i] = INF;
	}
	pq.push({ 0,1 });
	dist[1] = 0;
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		for (int i = 0; i < g[cur].size(); i++) {
			int next = g[cur][i].first;
			int ncost = g[cur][i].second;
			if (dist[next] > dist[cur] + ncost) {
				dist[next] = dist[cur] + ncost;
				pq.push({ dist[next],next });
				path[next] = cur;
			}
		}
	}
	return;
}
int main() {

	scanf("%d %d", &n, &m);
	g.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		g[a].push_back({ b,c });
		g[b].push_back({ a,c });
	}
	memset(path, -1, sizeof(path));
	dijstra();
	for (int i = 1; i <= n; i++) {
		if (path[i] == -1) continue;
		if (path[i] > i) ans.push_back({ i,path[i] });
		else ans.push_back({ path[i],i });
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
}