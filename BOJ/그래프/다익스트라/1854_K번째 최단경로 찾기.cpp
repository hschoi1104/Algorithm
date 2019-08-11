#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <functional>
using namespace std;
typedef pair<int, int> p;
vector<vector<p>>g;
vector<priority_queue<int, vector<int>>>se;
int INF = 999999999;
int a, b, c, v, e, k;
void dijk(int s) {
	priority_queue<p, vector<p>, greater<p>>pq;
	pq.push({ 0,s });
	se[1].push(0);

	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		for (int i = 0; i < g[cur].size(); i++) {
			int next = g[cur][i].first;
			int ncost = g[cur][i].second;

			if (se[next].size() < k) {
				se[next].push(cost + ncost);
			}
			else if (se[next].top() > cost + ncost) {
				se[next].pop();
				se[next].push(cost + ncost);
			}
			else continue;
			pq.push({ cost + ncost,next });
		}
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> v >> e >> k;
	g.resize(v + 1); se.resize(v + 1);
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		g[a].push_back({ b,c });
	}
	dijk(1);
	//정점 순회
	for (int i = 1; i <= v; i++) {
		//정점의 거리값들 사이즈로 예외처리
		if (se[i].size() < k) cout << "-1\n";
		else cout << se[i].top() << "\n";
	}
	return 0;
}