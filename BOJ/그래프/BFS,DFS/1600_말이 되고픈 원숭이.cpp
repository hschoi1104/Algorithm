#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
typedef struct node { int y, x, c, r; };
int k, w, h, ans = INT_MAX, arr[201][201], chk[31][201][201];
int dir[2][8][2] = { {{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}},{{-1,0},{0,1},{1,0},{0,-1} } };
queue<node>q;

void move(node cur, int pp, int r, int d) {
	for (int p = 0; p < pp; p++) {
		int ny = cur.y + dir[d][p][0];
		int nx = cur.x + dir[d][p][1];
		if (0 <= ny && ny < h && 0 <= nx && nx < w && arr[ny][nx] == 0 && chk[r][ny][nx] == 0) {
			q.push(node{ ny,nx,cur.c + 1,r });
			chk[r][ny][nx] = 1;
		}
	}
}
void bfs() {
	q.push(node{ 0,0,0,k });
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		if (cur.y == h - 1 && cur.x == w - 1) {
			ans = min(ans, cur.c);
			continue;
		}
		if (cur.r > 0) move(cur, 8, cur.r - 1, 0);
		move(cur, 4, cur.r, 1);
	}
	return;
}
int main() {
	FIO;
	cin >> k >> w >> h;
	for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) cin >> arr[i][j];
	bfs();
	ans = (ans == INT_MAX) ? -1 : ans;
	cout << ans;
	return 0;
}