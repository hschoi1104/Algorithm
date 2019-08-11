#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>
#include <limits.h>
using namespace std;
typedef pair<int, int> p;
vector<vector<p>>v;
int n, m, x;
int dist[1010];
int dijkstra(int s, int e) {
	priority_queue<p, vector<p>, greater<p>>pq;
	fill(dist, dist + 1001, INT_MAX);
	dist[s] = 0;
	pq.push({ 0,s }); // cost,pos
	for (int i = 1; i <= n; i++) if (i != s)pq.push({ INT_MAX,i });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int pos = pq.top().second;
		pq.pop();
		if (dist[pos] < cost) continue;
		for (int i = 0; i < v[pos].size(); i++) {
			int ncost = v[pos][i].second;
			int npos = v[pos][i].first;
			if (dist[npos] > dist[pos] + ncost) {
				dist[npos] = dist[pos] + ncost;
				pq.push({ dist[npos],npos });
			}
		}
	}
	return dist[e];
}
int main() {
	scanf("%d %d %d", &n, &m, &x);
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b,c });
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int res = 0;
		res += dijkstra(i, x);
		res += dijkstra(x, i);
		ans = max(ans, res);
	}
	printf("%d", ans);
	return 0;
}