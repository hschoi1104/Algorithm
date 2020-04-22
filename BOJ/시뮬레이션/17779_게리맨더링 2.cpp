#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
struct pos {
	int y, x;
};
int arr[21][21], brr[30][30], chk[30][30], ans[6], dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} }, n, res = INT_MAX;
queue<pos>q;
int count() {
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) ans[brr[i][j]] += arr[i][j];
	ans[5] += ans[0];
	int min_val = INT_MAX, max_val = 0;
	for (int i = 1; i <= 5; i++) min_val = min(min_val, ans[i]), max_val = max(max_val, ans[i]);
	return max_val - min_val;
}
void bfs(int sy, int ey, int sx, int ex, int y, int x, int num) {
	q.push({ y, x });
	brr[y][x] = num;
	chk[y][x] = 1;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = cur.y + dir[k][0], nx = cur.x + dir[k][1];
			if (sy <= ny && ny <= ey && sx <= nx && nx <= ex && !chk[ny][nx] && brr[ny][nx] == 0) {
				q.push({ ny,nx });
				chk[ny][nx] = 1;
				brr[ny][nx] = num;
			}
		}
	}
	return;
}
void draw(int y, int x, int d1, int d2) {
	int cy = y, cx = x;
	for (int k = 0; k <= d1; k++) brr[cy - k][cx + k] = 5;
	cy = y, cx = x;
	for (int k = 0; k <= d2; k++) brr[cy + k][cx + k] = 5;
	cy = y - d1, cx = x + d1;
	for (int k = 0; k <= d2; k++) brr[cy + k][cx + k] = 5;
	cy = y + d2, cx = x + d2;
	for (int k = 0; k <= d1; k++) brr[cy - k][cx + k] = 5;
	return;
}
bool chkd1d2(int y, int x, int d1, int d2) {
	if (x + d1 + d2 <= n && 1 <= y - d1 && y + d2 <= n) return true;
	return false;
}
void init() {
	memset(brr, 0, sizeof(brr));
	memset(chk, 0, sizeof(chk));
	memset(ans, 0, sizeof(ans));
}
void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> arr[i][j];
}
int solve() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int d1 = 1; d1 < n; d1++) {
				for (int d2 = 1; d2 < n; d2++) {
					if (!chkd1d2(i, j, d1, d2)) continue;
					init();
					draw(i, j, d1, d2);
					bfs(i, n, 1, j + d2 - 1, n, 1, 3);
					bfs(1, i - 1, 1, j + d1, 1, 1, 1);
					bfs(1, i - d1 + d2, j + d1 + 1, n, 1, n, 2);
					bfs(i - d1 + d2 + 1, n, j + d2, n, n, n, 4);

					res = min(res, count());
				}
			}
		}
	}
	return res;
}
int main() {
	FIO;
	input();
	cout << solve();
	return 0;
}