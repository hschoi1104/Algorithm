#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#define MAX 987654321
using namespace std;
typedef pair<int, int> p;
vector<vector<p>>g;
int dist[200010];
int v, e, s;

void go(int s) {
	priority_queue<p, vector<p>, greater<p>>pq;
	dist[s] = 0;
	pq.push({ 0,s });
	for (int i = 1; i <= v; i++) {
		if (i != s) pq.push({ MAX,i });
	}
	while (!pq.empty()) {
		int pos = pq.top().second;
		int weight = pq.top().first;
		pq.pop();
		if (dist[pos] < weight) continue;
		for (int k = 0; k < g[pos].size(); k++) {
			int npos = g[pos][k].first;
			int nweight = g[pos][k].second;
			if (dist[npos] > dist[pos] + nweight) {
				dist[npos] = dist[pos] + nweight;
				pq.push({ dist[npos],npos });
			}
		}
	}
	for (int i = 1; i <= v; i++) {
		if (dist[i] == MAX) {
			printf("INF\n");
		}
		else
			printf("%d\n", dist[i]);
	}
	return;
}
int main() {
	scanf("%d %d", &v, &e);
	g.resize(v + 1);
	fill(dist, dist + v + 1, MAX);
	scanf("%d", &s);
	for (int i = 0; i < e; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		g[a].push_back({ b,c });
	}
	go(s);
	return 0;
}