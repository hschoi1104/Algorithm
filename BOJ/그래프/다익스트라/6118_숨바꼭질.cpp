#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#define INF 1000000000
using namespace std;
typedef pair<int, int>p;
vector<vector<int>>v;
int dist[20005];
int chk[20005];
int n, m, a, b;

void dijkstra(int s) {
	priority_queue<p,vector<p>,greater<p>>pq;
	fill(dist, dist + 20002, INF);
	dist[s] = 0;
	for (int i = 1; i <= n; i++)pq.push({ dist[i],i });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		//if (dist[cur] < cost) continue;
		for (int i = 0; i < v[cur].size(); i++) {
			int npos = v[cur][i];
			if (dist[npos] > dist[cur] + 1) {
				dist[npos] = dist[cur] + 1;
				pq.push({ dist[npos] ,npos });
			}
		}
	}
	return;
}
int main() {
	scanf("%d %d", &n, &m);
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dijkstra(1);
	int maxdist = 0, maxbarn = 0, maxdistcnt = 0;
	for (int i = n; i >= 1; i--) {
		maxdist = max(maxdist, dist[i]);
		if (maxdist == dist[i]) maxbarn = i;
	}
	for (int i = n; i >= 1; i--) {
		if (maxdist == dist[i]) maxdistcnt += 1;
	}
	printf("%d %d %d\n", maxbarn, maxdist, maxdistcnt);
	return 0;
}