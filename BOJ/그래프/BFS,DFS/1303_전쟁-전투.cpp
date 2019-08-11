#include <stdio.h>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;
int arr[101][101];
int chk[101][101];
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int n, m;
char c;
int ansW = 0, ansB = 0;
int bfs(int y, int x, int team) {
	queue<pair<int, int>>q;
	q.push({ y,x });
	int cnt = 1, res = 1;
	chk[y][x] = cnt++;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int dy = y + dir[k][0];
			int dx = x + dir[k][1];
			if (0 <= dy && dy < n && 0 <= dx && dx < m && chk[dy][dx] == 0 && arr[dy][dx] == team) {
				q.push({ dy,dx });
				chk[dy][dx] = cnt;
				res = cnt;
				cnt++;
			}
		}
	}
	return res;
}
int main() {
	//input
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %1c", &c);
			if (c == 'W') arr[i][j] = 1; //w
			else arr[i][j] = 2;//b
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (chk[i][j] == 0) {
				if (arr[i][j] == 1) {//w
					int tmp = bfs(i, j, 1);
					ansW += tmp * tmp;
				}
				else {//b
					int tmp = bfs(i, j, 2);
					ansB += tmp * tmp;
				}
			}
		}
	}
	printf("%d %d", ansW, ansB);
	return 0;
}