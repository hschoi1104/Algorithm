#include <stdio.h>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
typedef pair<int, int> p;
queue<pair<pair<int, int>, int>>q;
int arr[51][51];
int chk[51][51];
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int n, m;
char ch;
p s,e;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		scanf(" %1c", &ch);
		if (ch == 'D') e = { i,j };
		else if (ch == 'S') s = { i,j };
		else if (ch == '.') arr[i][j] = 2500;
		else if (ch == 'X') arr[i][j] = -1;
		else if (ch == '*') {
			q.push({ {i,j},0 });
			chk[i][j] = 1;
		}
	}

	//bfs 수위레벨표기
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int level = q.front().second;
		chk[y][x] = 1;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = y + dir[k][0];
			int nx = x + dir[k][1];
			if (0 <= ny && ny < n && 0 <= nx && nx < m && chk[ny][nx] == 0 && arr[ny][nx] == 2500) {
				if ((e.first == ny && e.second == nx)||(s.first == ny && s.second == nx)) continue;
				q.push({{ny,nx},level+1});
				arr[ny][nx] = level + 1;
				chk[ny][nx] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++)memset(chk[i], 0, sizeof(chk[i]));
	//bfs 레벨에따른 시작점에서 도착지까지의 탐색
	q.push({ {s},0 });
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int level = q.front().second;
		chk[y][x] = 1;
		if (e.first == y && e.second == x) {
			printf("%d", level);
			return 0;
		}
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = y + dir[k][0];
			int nx = x + dir[k][1];
			if (0 <= ny && ny < n && 0 <= nx && nx < m && chk[ny][nx] == 0 && (arr[ny][nx] >level+1 || (ny == e.first && nx == e.second))) {
				q.push({ {ny,nx},level + 1 });
				chk[ny][nx] = 1;
				if (e.first == ny && e.second == nx) {
					printf("%d", level+1);
					return 0;
				}
			}
		}
	}
	printf("KAKTUS");
	return 0;
}