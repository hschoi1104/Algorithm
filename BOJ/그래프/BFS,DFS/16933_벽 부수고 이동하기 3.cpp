#include <stdio.h>
#include <queue>
using namespace std;
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int arr[1001][1001];
int chk[1001][1001][11][2];
int r, c, k;
int INF = 999999999;
struct node {
	int y, x, move, dist, day;
};
void bfs(int move) {
	queue<node>q;
	node s = { 0,0,move,1,1 };
	q.push(s);
	chk[0][0][move][1] = 1;
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int m = q.front().move;
		int di = q.front().dist;
		int da = q.front().day;
		if (y == r - 1 && x == c - 1) break;
		q.pop();
		for (int kk = 0; kk < 4; kk++) {
			int ny = y + dir[kk][0];
			int nx = x + dir[kk][1];
			//범위 체크
			if (0 <= ny && ny < r && 0 <= nx && nx < c) {
				//벽인 경우
				if (arr[ny][nx] == 1) {
					//낮
					if (da == 1) {
						//부수고 이동
						if (m != 0 && chk[ny][nx][m - 1][0] == 0) {
							chk[ny][nx][m - 1][0] = di+1;
							node temp = { ny,nx,m - 1,di + 1,0 };
							q.push(temp);
							if (ny == r - 1 && nx == c - 1) break;
						}
					}
					//밤
					else {
						//머무름
						if (chk[y][x][m][1] == 0) {
							chk[y][x][m][1] = di + 1;
							node temp = { y,x,m,di + 1,1 };
							q.push(temp);
							if (y == r - 1 && x == c - 1) break;
						}
					}
				}
				//벽이 아닌경우
				else {
					//낮
					if (da == 1) {
						if (chk[ny][nx][m][0] == 0) {
							chk[ny][nx][m][0] = di + 1;
							node temp = { ny,nx,m,di + 1,0 };
							q.push(temp);
							if (ny == r - 1 && nx == c - 1) break;
						}
					}
					//밤
					else {
						if (chk[ny][nx][m][1] == 0) {
							chk[ny][nx][m][1] = di + 1;
							node temp = { ny,nx,m,di + 1,1 };
							q.push(temp);
							if (ny == r - 1 && nx == c - 1) break;
						}
					}
				}
			}
		}
	}
}
int main() {
	scanf("%d %d %d", &r, &c, &k);
	for (int i = 0; i < r; i++) for (int j = 0; j < c; j++)scanf("%1d", &arr[i][j]);
	bfs(k);
	int ans = INF;
	for (int i = 0; i <= k; i++) {
		for (int du = 0; du <= 1; du++)	if (chk[r - 1][c - 1][i][du] != 0) ans = min(ans, chk[r - 1][c - 1][i][du]);
	}
	(ans == INF) ? printf("-1") : printf("%d", ans);
	return 0;
}