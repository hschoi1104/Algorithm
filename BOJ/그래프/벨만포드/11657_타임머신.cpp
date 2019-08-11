#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef pair<int, int>p;
vector<vector<p>>v;
int n, m;
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
	scanf("%d %d", &n, &m);
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b,c });
	}
	bellman();
	if (cycle == true) {
		printf("-1");
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		if (dist[i] == INT_MAX) printf("-1\n");
		else printf("%d\n", dist[i]);
	}
	return 0;
}