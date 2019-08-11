#include <stdio.h>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits.h>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int, ll>p;
vector<vector<p>>v;
stack<pair<int, int>>s;
int n, m, a, b;
ll c, ans = 0;
int path[1001];

void dijkstra(int ds, int de) {
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>pq;
	ll dist[1001];
	fill(dist, dist + 1001, LLONG_MAX);
	dist[1] = 0;
	for (int i = 1; i <= n; i++) pq.push({ dist[i],i });
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (dist[cur.second] < cur.first)continue;
		for (int i = 0; i < v[cur.second].size(); i++) {
			int npos = v[cur.second][i].first;
			int ncost = v[cur.second][i].second;
			if ((cur.second == ds && npos == de) || (cur.second == de && npos == ds))continue;
			if (dist[npos] > dist[cur.second] + ncost) {
				dist[npos] = dist[cur.second] + ncost;
				path[npos] = cur.second;
				pq.push({ dist[npos],npos });
			}
		}
	}
	if (dist[n] != LLONG_MAX) ans = max(ans, dist[n]);
	else return;
}
int main() {
	scanf("%d %d", &n, &m);
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %lld", &a, &b, &c);
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	dijkstra(0, 0);
	int cur = n;
	while (1) {
		s.push({ cur,path[cur] });
		if (path[cur] == 1) {
			break;
		}
		cur = path[cur];
	}

	while (!s.empty()) {
		auto it = s.top();
		dijkstra(it.first, it.second);
		s.pop();
	}
	printf("%lld", ans);
}