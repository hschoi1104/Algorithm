#include <stdio.h>
#include <queue>
using namespace std;
typedef pair<int, int> p;
queue<p> q;
int arr[1002][1002];
int chk[1002][1002];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int n, m, h, w, sr, sc, fr, fc;

bool chkmove(int y, int x, int dir) {
	//╩С
	if (dir == 0) {
		for (int i = x; i < x + w; i++) {
			if (arr[y - 1][i] == 1) return false;
		}
	}
	//©Л
	else if (dir == 1) {
		for (int i = y; i < y + h; i++) {
			if (arr[i][x + w] == 1) return false;
		}
	}
	//го
	else if (dir == 2) {
		for (int i = x; i < x + w; i++) {
			if (arr[y + h][i] == 1) return false;
		}
	}
	//аб
	else if (dir == 3) {
		for (int i = y; i < y + h; i++) {
			if (arr[i][x - 1] == 1) return false;
		}
	}
	return true;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	scanf("%d %d %d %d %d %d", &h, &w, &sr, &sc, &fr, &fc);
	q.push({ sr,sc });
	chk[sr][sc] = 1;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		if (cur.first == fr && cur.second == fc) {
			printf("%d", chk[cur.first][cur.second] - 1);
			return 0;
		}
		for (int k = 0; k < 4; k++) {
			int ny = cur.first + dir[k][0];
			int nx = cur.second + dir[k][1];
			if (0 < ny && ny <= n && 0 < nx && nx <= m && ny + h - 1 <= n && nx + w - 1 <= m && chk[ny][nx] == 0) {
				if (chkmove(cur.first, cur.second, k) == true) {
					chk[ny][nx] = chk[cur.first][cur.second] + 1;
					q.push({ ny,nx });
				}
			}
		}
	}
	printf("-1");
	return 0;
}