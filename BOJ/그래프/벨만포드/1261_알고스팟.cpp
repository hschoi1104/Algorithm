#include <stdio.h>
#include <queue>
#include <functional>
#include <limits.h>
using namespace std;
typedef pair<int, int> p;
int arr[102][102];
int dist[102][102];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int n, m;

int dijkstra() {
	priority_queue<pair<int, p>, vector<pair<int, p>>, greater<pair<int, p>>>pq;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) dist[i][j] = INT_MAX;
	dist[1][1] = 0;
	pq.push({ 0,{ 1,1 } });
	while (!pq.empty()) {
		auto pos = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		for (int k = 0; k < 4; k++) {
			int ny = pos.first + dy[k];
			int nx = pos.second + dx[k];
			int ncost = arr[ny][nx];
			if (dist[ny][nx] < ncost)continue;
			if (ny > 0 && ny <= n && nx > 0 && nx <= m) {
				if (dist[ny][nx] > dist[pos.first][pos.second] + ncost) {
					dist[ny][nx] = dist[pos.first][pos.second] + ncost;
					pq.push({ dist[ny][nx],{ ny,nx } });
				}
			}
		}
	}
	return dist[n][m];
}
int main() {
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	printf("%d\n", dijkstra());
	return 0;
}