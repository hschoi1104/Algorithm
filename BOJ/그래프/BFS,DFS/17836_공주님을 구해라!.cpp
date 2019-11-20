#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <string.h>
using namespace std;
typedef pair<int, int> p;
int arr[101][101];
int chk[101][101], ans = INT_MAX;
p gum;
int n, m, t;
queue<p>q;
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
void bfs() {
	q.push({ 0,0 });
	chk[0][0] = 0;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = y + dir[k][0];
			int nx = x + dir[k][1];
			if (0 <= ny && ny < n && 0 <= nx && nx < m && (arr[ny][nx] == 0 || arr[ny][nx] == 2) && chk[ny][nx] == -1) {
				chk[ny][nx] = chk[y][x] + 1;
				q.push({ ny,nx });
			}
		}
	}
	return;
}

int main() {
	scanf("%d %d %d", &n, &m, &t);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2) gum = { i,j };
		}
	}
	memset(chk, -1, sizeof(chk));
	bfs();
	int Min = 1e8;
	if (chk[n - 1][m - 1] != -1) Min = chk[n - 1][m - 1];
	if (chk[gum.first][gum.second] != -1) Min = min(Min, chk[gum.first][gum.second] + n - 1 - gum.first + m - 1 - gum.second);
	if (gum.first == 0 && gum.second == 0) Min = n - 1 + m - 1;
	if (Min == 0 || Min > t) cout << "Fail";
	else printf("%d", Min);
	return 0;
}