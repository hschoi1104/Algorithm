#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
vector<vector<p>>v;
ll INF = 1000000000;
int n, m;
ll k1, k2;
ll ans = 0;
ll dist[810];
void dijkstra(ll s, ll e) {
	priority_queue<p, vector<p>, greater<p>>pq;
	fill(dist, dist + 801, INF);
	dist[s] = 0;
	pq.push({ 0,s }); // cost,pos
	for (int i = 1; i <= n; i++) if (i != s)pq.push({ INF,i });
	while (!pq.empty()) {
		ll cost = pq.top().first;
		ll pos = pq.top().second;
		pq.pop();
		if (dist[pos] < cost) continue;
		for (int i = 0; i < v[pos].size(); i++) {
			ll ncost = v[pos][i].second;
			ll npos = v[pos][i].first;
			if (dist[npos] > dist[pos] + ncost) {
				dist[npos] = dist[pos] + ncost;
				pq.push({ dist[npos],npos });
			}
		}
	}
	ans += dist[e];
}
int main() {
	scanf("%d %d", &n, &m);
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		ll a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	scanf("%lld %lld", &k1, &k2);
	dijkstra(1, k1);
	dijkstra(k1, k2);
	dijkstra(k2, n);
	ll res = ans;
	ans = 0;
	dijkstra(1, k2);
	dijkstra(k2, k1);
	dijkstra(k1, n);
	ans = min(ans, res);
	if (ans >= INF) printf("-1\n");
	else printf("%lld\n", ans);
	return 0;
}