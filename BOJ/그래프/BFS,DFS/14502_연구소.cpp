#include <stdio.h>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
int n, m;
int map[10][10];
int map2[10][10];
int  dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
vector<pair<int, int>>v;
queue<pair<int, int>>q;
int ans = 0;
void bfs() {
	int visited[10][10];

	for (int i = 0; i < n; i++) memset(visited, 0, sizeof(visited));
	while (!q.empty()) {
		auto cur = q.front();
		visited[cur.first][cur.second] = 2;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = cur.first + dir[k][0];
			int nx = cur.second + dir[k][1];
			if (ny >= 0 && ny < n && nx >= 0 && nx < m && visited[ny][nx] == 0 && map2[ny][nx] == 0) {
				visited[ny][nx] = 1;
				map2[ny][nx] = 2;
				q.push({ ny,nx });
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map2[i][j] == 0) cnt++;
		}
	}
	ans = max(ans, cnt);
}
int main() {
	scanf("%d %d", &n, &m);
	//input
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) v.push_back({ i,j });
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j]) continue;
			for (int k = 0; k < n; k++) {
				for (int l = 0; l < m; l++) {
					if (map[k][l]) continue;
					if (k == i && l == j)continue;
					for (int a = 0; a < n; a++) {
						for (int b = 0; b < m; b++) {
							if (map[a][b]) continue;
							if ((k == a && l == b) || (a == i && b == j))continue;
							//push 2
							for (int o = 0; o < v.size(); o++) {
								q.push(v[o]);
							}

							for (int i = 0; i < n; i++) {
								for (int j = 0; j < m; j++) {
									map2[i][j] = map[i][j];
								}
							}
							map2[i][j] = 1;
							map2[k][l] = 1;
							map2[a][b] = 1;
							//bfs
							bfs();
						}
					}
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}