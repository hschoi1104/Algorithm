#include <stdio.h>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
typedef pair<int, int> p;
int arr[301][301];
int chk[301][301];
int dir[4][2] = { {1,0},{0,-1},{-1,0},{0,1} };
int n, m, years = 0;
void bfs(int y, int x) {
	queue<p>q;
	q.push({ y,x });
	chk[y][x] = 1;
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = cy + dir[k][0];
			int nx = cx + dir[k][1];
			if (0 <= ny && ny < n && 0 <= nx && nx < m && chk[ny][nx] == 0 && arr[ny][nx] != 0) {
				q.push({ ny,nx });
				chk[ny][nx] = 1;
			}
		}
	}
	return;
}
void init() {
	for (int i = 0; i < n; i++) memset(chk[i], 0, sizeof(chk[i]));
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)scanf("%d", &arr[i][j]);
	while (1) {
		//두덩어리 인지 체크
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != 0 && chk[i][j] == 0) {
					bfs(i, j);
					cnt += 1;
					if (cnt >= 2) {
						printf("%d", years);
						return 0;
					}
				}
			}
		}
		if (cnt == 0) {
			printf("0");
			return 0;
		}
		init();
		bool flag = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != 0 && chk[i][j] == 0) {
					chk[i][j] = 1;
					int c = 0;
					for (int k = 0; k < 4; k++) {
						int ny = i + dir[k][0];
						int nx = j + dir[k][1];
						if (ny >= 0 && ny < n && 0 <= nx && nx < m && arr[ny][nx] == 0 && chk[ny][nx] == 0) c += 1;
					}
					if (c != 0) flag = true;
					arr[i][j] -= c;
					if (arr[i][j] < 0) arr[i][j] = 0;
				}
			}
		}
		if (flag == false) {
			printf("0");
			return 0;
		}
		years += 1;
		init();
	}
	return 0;
}