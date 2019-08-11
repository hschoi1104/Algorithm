#include <stdio.h>
#include <queue>
using namespace std;
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int arr[1001][1001];
int chk[1001][1001][11];
int r, c, k;
int INF = 999999999;
struct node {
	int y, x, u, d;
};
void bfs(int move) {
	queue<node>q;
	node s = { 0,0,move,1 };
	q.push(s);
	chk[0][0][1] = 1;
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int u = q.front().u;
		int d = q.front().d;
		if (y == r - 1 && x == c - 1) break;
		q.pop();
		for (int kk = 0; kk < 4; kk++) {
			int ny = y + dir[kk][0];
			int nx = x + dir[kk][1];
			if (0 <= ny && ny < r && 0 <= nx && nx < c && chk[ny][nx][u] == 0) {
				//���ΰ��
				if (arr[ny][nx] == 1) {
					//�νǼ��ִٸ� �νð� ����
					if (u !=0 && chk[ny][nx][u - 1] == 0) {
						node temp = { ny,nx,u - 1,d + 1 };
						q.push(temp);
						chk[ny][nx][u - 1] = d + 1;
						if (ny == r - 1 && nx == c - 1) break;
					}
					//�Ⱥνô� ���� �ʿ����
				}
				//���� �ƴѰ�� �׳� ����
				else if (arr[ny][nx] == 0 && chk[ny][nx][u] == 0) {
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
	scanf("%d %d %d", &r, &c, &k);
	for (int i = 0; i < r; i++) for (int j = 0; j < c; j++)scanf("%1d", &arr[i][j]);
	bfs(k);
	int ans = INF;
	for (int i = 0; i <= k; i++) {
		if (chk[r - 1][c - 1][i] != 0) ans = min(ans,chk[r - 1][c - 1][i]);
	}
	(ans == INF) ? printf("-1") : printf("%d", ans);
	return 0;
}