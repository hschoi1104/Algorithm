#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
typedef pair<int, int> p;
vector<vector<p>>g;
int chk[100001];
int v, e, a, b, c, ans = 0,maxweight=0;
int prim() {
	priority_queue<p, vector<p>, greater<p>> pq;//거리,정점
	pq.push({ 0,1 });
	while (!pq.empty()) {
		p cur = pq.top();
		pq.pop();
		if (chk[cur.second]) continue;
		else chk[cur.second] = 1;
		ans += cur.first;
		maxweight = max(maxweight, cur.first);
		for (int i = 0; i < g[cur.second].size(); i++) {
			p next = g[cur.second][i];
			if (!chk[next.second]) pq.push(next);
		}
	}
	return ans;
}
int main() {
	scanf("%d %d", &v, &e);
	g.resize(v + 1);
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		g[a].push_back({ c,b }); g[b].push_back({ c,a });
	}
	printf("%d", prim()-maxweight);
	return 0;
}