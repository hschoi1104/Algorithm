#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
typedef pair<p, int> pp;
char arr[11][11];
int chk[11][11];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
p s, e;
int bfs() {
	queue<pp>q;
	q.push({s,0});
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (arr[y][x] == 'L') return cnt;
		chk[y][x] = 1;
		for (int k = 0; k < 4; k++) {
			int ny = y + dir[k][0];
			int nx = x + dir[k][1];
			if (0 <= ny && ny < 10 && 0 <= nx && nx < 10 && chk[ny][nx] == 0 && arr[ny][nx] != 'R') {
				if (arr[ny][nx] == 'L') return cnt + 1;
				q.push({ {ny,nx},cnt + 1 });
				chk[ny][nx] = 1;
			}
		}

	}
	return 0;
}
int main() {
	for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) {
		scanf(" %1c", &arr[i][j]);
		if (arr[i][j] == 'B') s = { i,j };
		else if (arr[i][j] == 'L') e = { i,j };
	}
	printf("%d", bfs()-1);
	return 0;
}