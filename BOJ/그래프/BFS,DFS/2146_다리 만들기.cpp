#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int INF = 9999999999;
struct node {
	int y, x, cnt;
};
int arr[101][101];//rand
int ocean[101][101];//ocean
int chk[101][101];
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int n;
void bfsrand(int y, int x, int num) {
	queue<node>q;
	node s = { y,x };
	q.push(s);
	chk[y][x] = 1;
	while (!q.empty()) {
		int y = q.front().y; int x = q.front().x;
		q.pop();
		chk[y][x] = 1; arr[y][x] = num;
		for (int k = 0; k < 4; k++) {
			int dy = y + dir[k][0]; int dx = x + dir[k][1];
			if (0 <= dy && dy < n && 0 <= dx && dx < n && chk[dy][dx] == 0 && arr[dy][dx] == 1) {
				arr[dy][dx] = num; chk[dy][dx] = 1;
				node t = { dy,dx };
				q.push(t);
			}
		}
	}
	return;
}
void bfsocean(int y, int x) {
	queue<node>q;
	node s = { y,x };
	q.push(s);
	chk[y][x] = 1;
	while (!q.empty()) {
		int y = q.front().y; int x = q.front().x;
		q.pop();
		chk[y][x] = 1;
		for (int k = 0; k < 4; k++) {
			int dy = y + dir[k][0]; int dx = x + dir[k][1];
			if (0 <= dy && dy < n && 0 <= dx && dx < n) {
				if (chk[dy][dx] == 0 && arr[dy][dx] == 0) {
					chk[dy][dx] = 1;
					node t = { dy,dx };
					q.push(t);
				}
				if (arr[dy][dx]) ocean[dy][dx] = 1;
			}
		}
	}
	return;
}
int bfsbridge(int y, int x, int start) {
	queue<node>q;
	node s = { y,x,0 };
	q.push(s);
	chk[y][x] = 1;
	while (!q.empty()) {
		int y = q.front().y; int x = q.front().x; int cnt = q.front().cnt;
		q.pop();
		chk[y][x] = 1;
		for (int k = 0; k < 4; k++) {
			int dy = y + dir[k][0]; int dx = x + dir[k][1];
			if (0 <= dy && dy < n && 0 <= dx && dx < n) {
				if (arr[dy][dx] != 0 &&arr[dy][dx] != start) return cnt;
				if (chk[dy][dx] == 0 && arr[dy][dx] == 0) {
					chk[dy][dx] = 1;
					node t = { dy,dx ,cnt + 1 };
					q.push(t);
				}
			}
		}
	}
	return INF;
}
void initchk() {
	for (int i = 0; i < n; i++) memset(chk[i], 0, sizeof(chk[i]));
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	//육지 넘버링
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] && chk[i][j] == 0) bfsrand(i, j, cnt++);
		}
	}

	initchk();
	//바다인접 육지 체크
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] && chk[i][j] == 0) bfsocean(i, j);
		}
	}
	initchk();
	int ans = INF;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ocean[i][j]) {
				initchk();
				ans = min(ans,bfsbridge(i, j, arr[i][j]));
			}
		}
	}
	printf("%d", ans);
	return 0;
}