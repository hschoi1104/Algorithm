#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <functional>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
vector<vector<p>>g;
vector<ll>cow, flow, cost, path, res;
int chk[10005];
void dijk() {
	memset(chk, 0, sizeof(chk));
	fill(path.begin(), path.end(), -1);
	fill(cost.begin(), cost.end(), LLONG_MAX);
	priority_queue<p, vector<p>, greater<p>>pq;
	cost[1] = 0;
	pq.push({ 0,1 });
	while (!pq.empty()) {
		ll cur = pq.top().second;
		ll ccost = pq.top().first;
		pq.pop();
		chk[cur] = 1;
		for (ll i = 0; i < g[cur].size(); i++) {
			ll next = g[cur][i].first;
			ll ncost = g[cur][i].second;
			if (chk[next] == 1) continue;
			if (cost[next] > cost[cur] + ncost) {
				cost[next] = cost[cur] + ncost;
				path[next] = cur;
				pq.push({ cost[next],next });
			}
			else if (cost[next] == cost[cur] + ncost) {
				if (path[next] > cur) {
					cost[next] = cost[cur] + ncost;
					path[next] = cur;
					pq.push({ cost[next],next });
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b, c, n, m;
	ll ans = 0, t; cin >> n >> m >> t;
	g.resize(n + 1); cow.resize(n + 1); flow.resize(n + 1); cost.resize(n + 1); path.resize(n + 1);
	for (ll i = 1; i <= n; i++) cin >> cow[i];
	for (ll i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		g[a].push_back({ b,c });
		g[b].push_back({ a,c });
	}
	dijk();
	for (ll i = 1; i <= n; i++) {
		ll cur = i;
		while (cur != -1) {
			flow[cur] += cow[i];
			cur = path[cur];
		}
	}

	for (int i = 1; i <= n; i++) ans = max(ans, flow[i] * (cost[i] - t));
	cout << ans << "\n";
	return 0;
}