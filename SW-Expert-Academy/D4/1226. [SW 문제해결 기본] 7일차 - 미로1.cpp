#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
int dir[4][2] = { {1,0},{0,-1},{0,1},{-1,0} };
int arr[17][17];
int chk[17][17];
queue<p>q;
void init() {
	for (int i = 0; i < 17; i++) for (int j = 0; j < 17; j++) chk[i][j] = arr[i][j] = 0;
}
void bfs(int y, int x) {
	q.push({ y,x });
	chk[y][x] = 1;
	while (!q.empty()) {
		auto cur = q.front();
		chk[cur.first][cur.second] = 1;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int dy = cur.first + dir[k][0];
			int dx = cur.second + dir[k][1];
			if (0 <= dy && dy < 16 && 0 <= dx && dx < 16 && chk[dy][dx] == 0 && arr[dy][dx] != 1) {
				q.push({ dy,dx });
			}
		}
	}
	return;
}

int main() {
	int t = 10;
	while (t--) {
		init();
		int n; scanf("%d",&n);
		p s, e;
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				scanf("%1d", &arr[i][j]);
				if (arr[i][j] == 2) s = { i,j };
				else if (arr[i][j] == 3) e = { i,j };
			}
		}
		bfs(s.first, s.second);
		int flag = (chk[e.first][e.second] == 1) ? 1 : 0;
		printf("#%d %d\n", n, flag);
	}
	return 0;
}