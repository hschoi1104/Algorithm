#include <stdio.h>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;
typedef pair<int, int> p;
int n, m;//세로 가로
int arr[21][21];
int map[21][21];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int maxt = 0;
int ans = INT_MAX;
void bfs(int y1, int x1, int y2, int x2) {
	maxt = 0;
	for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++)	arr[i][j] = 0;
	queue<pair<p, int>>q;
	q.push({ { y1,x1 },0 });
	q.push({ { y2,x2 },0 });
	while (!q.empty()) {
		auto cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = cur.first + dy[k];
			int nx = cur.second + dx[k];
			if (ny >= 0 && ny < n && nx >= 0 && nx < m &&arr[ny][nx] == 0) {
				arr[ny][nx] = cnt + 1;
				q.push({ {ny,nx},cnt + 1 });
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) maxt = max(maxt, arr[i][j]);
		}
	}
	ans = min(ans, maxt);
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) continue;
			for (int o = i; o < n; o++) {
				for (int p = j+1; p < m; p++) {
					if (map[o][p] == 1)continue;
					bfs(i, j, o, p);
				}
			}
		}
	}
	printf("%d", ans);
	return  0;
}