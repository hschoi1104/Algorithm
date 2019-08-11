#include <stdio.h>
#include <queue>
using namespace std;
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int arr[1001][1001];
int chk[1001][1001][2];
int r, c;
struct node {
	int y, x, u, d;
};
void bfs() {
	queue<node>q;
	node s = { 0,0,1,1 };
	q.push(s);
	chk[0][0][1] = 1;
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int u = q.front().u;
		int d = q.front().d;
		if (y == r - 1 && x == c - 1) break;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = y + dir[k][0];
			int nx = x + dir[k][1];
			if (0 <= ny && ny < r && 0 <= nx && nx < c && chk[ny][nx][u] == 0) {
				//벽인경우
				if (arr[ny][nx] == 1) {
					//부실수있다면 부시고 진행
					if (u == 1 && chk[ny][nx][u - 1]==0) {
						node temp = { ny,nx,u - 1,d + 1 };
						q.push(temp);
						chk[ny][nx][u - 1] = d + 1;
						if (ny == r - 1 && nx == c - 1) break;
					}
					//안부시는 경우는 필요없음
				}
				//벽이 아닌경우 그냥 진행
				else if (arr[ny][nx] == 0 && chk[ny][nx][u]==0) {
					node temp = { ny,nx,u,d + 1 };
					q.push(temp);
					chk[ny][nx][u] = d + 1;
					if (ny == r - 1 && nx == c - 1) break;
				}
			}
		}
	}
}
int main() {
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) for (int j = 0; j < c; j++)scanf("%1d", &arr[i][j]);
	bfs();
	int ans = min(chk[r - 1][c - 1][0], chk[r - 1][c - 1][1]);
	if (chk[r - 1][c - 1][0] != 0 && chk[r - 1][c - 1][1] != 0) printf("%d", ans);
	else if (chk[r - 1][c - 1][0] == 0 && chk[r - 1][c - 1][1] == 0) printf("-1");
	else printf("%d", max(chk[r - 1][c - 1][0], chk[r - 1][c - 1][1]));
	return 0;
}