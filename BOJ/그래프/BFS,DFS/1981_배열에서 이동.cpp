#include <stdio.h>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <string.h>
using namespace std;
typedef pair<int, int> p;
int arr[101][101];
bool chk[101][101];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int n, left, right, ans = INT_MAX, maxval = -1, minval = 201;
bool bfs(int mid) {
	queue<p>q;
	for (int o = minval; o <= maxval; o++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (o <= arr[i][j] && arr[i][j] <= o + mid)chk[i][j] = false;
				else chk[i][j] = true;
			}
		}
		while (!q.empty()) q.pop();
		if (chk[0][0] == false)q.push({ 0,0 });
		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			if (y == n - 1 && x == n - 1) return true;
			chk[y][x] = true;
			for (int k = 0; k < 4; k++) {
				int dy = y + dir[k][0];
				int dx = x + dir[k][1];
				if (0 <= dy && dy < n && 0 <= dx && dx < n && chk[dy][dx] == false) {
					q.push({ dy,dx });
					chk[dy][dx] = true;
					if (dy == n - 1 && dx == n - 1) return true;
				}
			}
		}
	}
	return false;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) {
		scanf("%d", &arr[i][j]);
		maxval = max(maxval, arr[i][j]);
		minval = min(minval, arr[i][j]);
	}
	right = maxval - minval;
	left = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		bool res = bfs(mid);
		if (res == true)right = mid - 1;
		else left = mid + 1;
	}
	printf("%d", left);
	return 0;
}