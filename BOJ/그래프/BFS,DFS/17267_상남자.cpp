#include <stdio.h>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;
typedef pair<int, int> p;
typedef struct node {
	int y, x, left, right;
};
int map[1100][1100], chk[1100][1100], dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int n, m, l, r;
p s;
queue<node>q;
void bfs() {
	node st{ s.first,s.second,l,r };
	chk[s.first][s.second] = st.left;
	q.push(st);
	while (!q.empty()) {
		node cur = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			if (cur.left <= 0 && k == 2) continue;
			if (cur.right <= 0 && k == 0) continue;
			int ny = cur.y + dir[k][0];
			int nx = cur.x + dir[k][1];
			if (0 <= ny && ny < n && 0 <= nx && nx < m && chk[ny][nx] < cur.left && map[ny][nx] != 1) {
				node next;
				//¿À¸¥ÂÊ
				if (k == 0) next = { ny,nx,cur.left,cur.right - 1 };
				//¿ÞÂÊ
				else if (k == 2) next = { ny,nx,cur.left - 1,cur.right };
				else next = { ny,nx,cur.left,cur.right };
				q.push(next);
				chk[ny][nx] = next.left;
			}
		}
	}
	return;
}
int main() {
	scanf("%d %d %d %d", &n, &m, &l, &r);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
			if (map[i][j] == 2) {
				s = { i,j };
				map[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) chk[i][j] = -1;
	bfs();
	int cnt = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (chk[i][j] != -1) cnt += 1;

	printf("%d\n", cnt);
	return 0;
}