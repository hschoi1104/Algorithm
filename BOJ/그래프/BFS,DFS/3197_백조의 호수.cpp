#include <stdio.h>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
typedef pair<int, int> p;
char arr[1510][1510];
int chk[1510][1510];
int chk2[1510][1510];
struct node {
	int y;
	int x;
	int cnt;
};
queue<node>q;
queue<node>q2;
vector<p>bird;
int dir[4][2] = { {0,1} ,{1,0},{0,-1},{-1,0} };
int r, c;
void bfs() {
	while (!q.empty()) {
		node cur = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int dy = cur.y + dir[k][0];
			int dx = cur.x + dir[k][1];
			if (0 <= dy && dy < r && 0 <= dx && dx < c && chk[dy][dx] == -1) {
				node next = { dy,dx,cur.cnt + 1 };
				chk[next.y][next.x] = cur.cnt + 1;
				q.push(next);
			}
		}
	}
	return;
}
bool bfs2(int cnt) {
	while (!q2.empty()) {
		node cur = q2.front();
		q2.pop();
		if (cur.y == bird[1].first && cur.x == bird[1].second) return true;
		for (int k = 0; k < 4; k++) {
			int dy = cur.y + dir[k][0];
			int dx = cur.x + dir[k][1];
			if (0 <= dy && dy < r && 0 <= dx && dx < c && chk2[dy][dx] == 0 && chk[dy][dx]<=cnt) {
				node next = { dy,dx };
				if (next.y == bird[1].first && next.x == bird[1].second) return true;
				chk2[next.y][next.x] = 1;
				q2.push(next);
			}
		}
	}
	return false;
}
int main() {
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf(" %1c", &arr[i][j]);
			if (arr[i][j] == '.') {
				node temp = { i,j,0 };
				chk[i][j] = 0;
				q.push(temp);
			}
			else if (arr[i][j] == 'L') {
				bird.push_back({ i,j });
				chk[i][j] = 0;
				node temp = { i,j,0 };
				q.push(temp);
			}
			else chk[i][j] = -1;
		}
	}
	bfs();
	int left = 0, right = 1600;
	while (left <= right) {
		int mid = (left + right) / 2;
		while (!q2.empty()) q2.pop();
		for (int i = 0; i < r; i++) memset(chk2[i], 0, sizeof(chk2[i]));
		q2.push({ bird[0].first, bird[0].second });
		chk2[bird[0].first][bird[0].second]=1;

		int res = bfs2(mid);
		
		if (res == true) {
			right = mid - 1;
		}
		else left = mid + 1;
	}
	printf("%d\n", left);
	return 0;
}