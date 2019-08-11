#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef pair<int, int>p;
vector<vector<p>>v;
int n, m, t, c, w;
int dist[510];
bool cycle = false;
void bellman() {
	fill(dist, dist + 501, INT_MAX);
	dist[1] = 0;
	for (int k = 0; k < n; k++) {
		for (int j = 1; j <= n; j++) {
			for (int i = 0; i < v[j].size(); i++) {
				int npos = v[j][i].first;
				int ncost = v[j][i].second;
				if (dist[j] != INT_MAX && dist[npos] > dist[j] + ncost) {
					dist[npos] = dist[j] + ncost;
					if (k == n - 1) cycle = true;
				}
			}
		}
	}
}
int main() {
	scanf("%d", &c);
	while (c--) {
		v.clear();
		cycle = false;
		scanf("%d %d %d", &n, &m, &w);
		v.resize(n + 1);
		for (int i = 0; i < m; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			v[a].push_back({ b,c });
			v[b].push_back({ a,c });
		}
		for (int i = 0; i < w; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			v[a].push_back({ b,-c });
		}
		bellman();
		if (cycle == true) 	printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}