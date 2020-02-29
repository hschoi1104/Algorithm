#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
typedef struct node {
	ll e, val;
	bool operator < (const node& tmp) const {
		return val > tmp.val;
	}
};
priority_queue<node>pq;
vector<vector<p>>v;
ll pos[100001], dist[100001], n, m, k;
p dijkstra() {
	for (int i = 1; i <= n; i++) {
		ll cost = 1e17;
		if (pos[i]) cost = 0;
		pq.push(node{ i,cost });
		dist[i] = cost;
	}
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (dist[cur.e] < cur.val) continue;
		for (int i = 0; i < v[cur.e].size(); i++) {
			ll next = v[cur.e][i].first;
			ll cost = v[cur.e][i].second;
			if (dist[next] > cur.val + cost) {
				dist[next] = cur.val + cost;
				pq.push(node{ next,dist[next] });
			}
		}
	}
	p ans = { 0,0 };
	for (int i = 1; i <= n; i++) {
		if (dist[i] != 1e17 && ans.first < dist[i]) ans = { dist[i],i };
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int s, e, c; cin >> s >> e >> c;
		v[e].push_back({ s,c });
	}
	for (int i = 0; i < k; i++) {
		int x; cin >> x;
		pos[x] = 1;
	}
	p res = dijkstra();
	cout << res.second << "\n" << res.first;
	return 0;
}