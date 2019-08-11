#include <stdio.h>
#include <queue>
using namespace std;
typedef pair<int, int> p;
typedef struct node {
	int y, x;
};
int n;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
char arr[1002][1002];
int chk[1002][1002];
p bfs(int i, int j) {
	int b = 0;
	int p = 0;
	queue<node>q;
	q.push(node{ i,j });
	chk[i][j] = 1;
	while (!q.empty()) {
		node cur = q.front();
		q.pop();
		b += 1;
		chk[cur.y][cur.x] = 1;
		for (int k = 0; k < 4; k++) {
			int ny = cur.y + dir[k][0];
			int nx = cur.x + dir[k][1];
			if (0 <= ny && ny <= n+1 && 0 <= nx && nx <= n+1) {
				//blob
				if (arr[ny][nx] == '#' && chk[ny][nx] == 0) {
					chk[ny][nx] = 1;
					q.push(node{ ny,nx });
				}
				//empty
				if (arr[ny][nx] == '.') {
					p += 1;
				}
			}
		}
	}
	return { b,p };
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i <= n+1; i++) for (int j = 0; j <= n+1; j++) arr[i][j] = '.';
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
		scanf(" %1c", &arr[i][j]);
	}
	p ans = { 0,0 };
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			p res;
			if (arr[i][j] == '#' && chk[i][j] == 0) res = bfs(i, j);
			if (res.first > ans.first) ans = res;
			else if (res.first == ans.first) ans.second = min(ans.second, res.second);
		}
	}
	printf("%d %d", ans.first, ans.second);
	return 0;
}