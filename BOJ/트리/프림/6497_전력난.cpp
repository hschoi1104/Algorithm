#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <string.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
vector<vector<p>>g;
int chk[200001];
int v, e, a, b, c;
ll ans = 0, sum = 0;
ll prim() {
	memset(chk, 0, sizeof(chk));
	priority_queue<p, vector<p>, greater<p>> pq;//거리,정점
	pq.push({ 0,1 });
	while (!pq.empty()) {
		p cur = pq.top();
		pq.pop();
		if (chk[cur.second]) continue;
		else chk[cur.second] = 1;
		ans += cur.first;
		for (int i = 0; i < g[cur.second].size(); i++) {
			p next = g[cur.second][i];
			if (!chk[next.second]) pq.push(next);
		}
	}
	return ans;
}
int main() {
	while (1) {
		ans = sum = 0;
		scanf("%d %d", &v, &e);
		if (v == 0 && e == 0) break;
		g.resize(v + 1);
		for (int i = 0; i < e; i++) {
			scanf("%d %d %d", &a, &b, &c);
			sum += c;
			g[a].push_back({ c,b }); g[b].push_back({ c,a });
		}
		printf("%d\n", sum - prim());
		g.clear();
	}
	return 0;
}