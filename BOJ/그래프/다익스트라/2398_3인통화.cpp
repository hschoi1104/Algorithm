#include <stdio.h>
#include <queue>
#include <algorithm>
#include <functional>
#include <string.h>
using namespace std;
vector<vector<pair<int, int>>>g;
vector<pair<int, int>>path;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
int dist[1002][1002];
int v, e, a, b, c, s, d1, d2, d3, center = 0;
int INF = 999999999;
int dijkstra(int s, int e) {
	dist[s][s] = 0;
	pq.push({ 0,s });
	for (int i = 1; i <= v; i++) {
		if (i == s) continue;
		pq.push({ INF,i });
		dist[i][s] = INF;
	}

	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (dist[cur][s] < cost) continue;
		for (int i = 0; i < g[cur].size(); i++) {
			int next = g[cur][i].first;
			int ncost = g[cur][i].second;
			if (dist[next][s] > dist[cur][s] + ncost) {
				dist[next][s] = dist[cur][s] + ncost;
				pq.push({ dist[next][s],next });
			}
		}
	}
	return dist[e][s];
}
void bfs(int pos, int anscost) {
	queue<pair<int, int>>q;
	int chk[1001];
	memset(chk, 0, sizeof(chk));
	q.push({ pos,anscost });
	chk[pos] = 1;
	while (!q.empty()) {
		int cur = q.front().first;
		int cost = q.front().second;
		q.pop();
		for (int i = 0; i < g[cur].size(); i++) {
			int next = g[cur][i].first;
			int ncost = g[cur][i].second;
			if (chk[next]==0 &&cost == dist[next][center]+ncost) {
				q.push({ next,cost - ncost });
				chk[next] = 1;
				if (cur > next)
					path.push_back({ next,cur });
				else
					path.push_back({ cur,next });
			}

		}
	}
}
int main() {
	scanf("%d %d", &v, &e);
	g.resize(v + 1);
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		g[a].push_back({ b,c });
		g[b].push_back({ a,c });
	}
	scanf("%d %d %d", &d1, &d2, &d3);
	pair<int, int> minans = {INF,0};
	for (int i = 1; i <= v; i++) {
		dijkstra(i, 1);
	}
	for (int i = 1; i <= v; i++) {
		if (dist[i][d1] + dist[i][d2] + dist[i][d3] < minans.first) {
			minans = { dist[i][d1] + dist[i][d2] + dist[i][d3],i };
		}
	}
	
	center = minans.second;
	bfs(d1,dist[d1][center]);
	bfs(d2, dist[d2][center]);
	bfs(d3, dist[d3][center]);
	path.erase(unique(path.begin(), path.end()),path.end());
	sort(path.begin(), path.end());
	printf("%d %d\n", minans.first, path.size());
	for (int i = 0; i < path.size(); i++) {
		printf("%d %d\n", path[i].first, path[i].second);
	}
	return 0;
}
