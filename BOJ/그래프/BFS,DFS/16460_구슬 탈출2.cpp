#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> p;
char map[11][11];
int chk[11][11][11][11];
p des = { 0,0 };
p r = { 0,0 };
p b = { 0,0 };
typedef struct ndoe {
	int ry;
	int rx;
	int by;
	int bx;
	int cnt;
}node;
int n, m, x;

int bfs() {
	queue <node> q;
	node s = { r.first,r.second,b.first,b.second,0 };
	q.push(s);
	while (!q.empty()) {
		node cur = q.front();
		q.pop();
		if (cur.cnt > 9)continue;
		chk[cur.ry][cur.rx][cur.by][cur.bx] = 1;
		p nr = { cur.ry,cur.rx };
		p nb = { cur.by,cur.bx };
		//상
		if (map[cur.ry - 1][cur.rx] != '#' || map[cur.by - 1][cur.bx] != '#') {
			bool redflag = false, blueflag = false;
			if (cur.ry <= cur.by) {
				//빨간구슬 먼저 이동
				for (int i = cur.ry - 1; i >= 0; i--) {
					if (map[i][cur.rx] == 'O') {
						redflag = true;
						nr = { 0,0 };
					}
					else if (map[i][cur.rx] == '#' || (i == nb.first && cur.rx == nb.second)) break;
					else nr = { i,cur.rx };
				}
				//파란구슬 이동
				for (int i = cur.by - 1; i >= 0; i--) {
					if (map[i][cur.bx] == 'O') blueflag = true;
					else if (map[i][cur.bx] == '#' || (i == nr.first && cur.bx == nr.second)) break;
					else nb = { i,cur.bx };
				}
			}
			else {
				//파란구슬 이동
				for (int i = cur.by - 1; i >= 0; i--) {
					if (map[i][cur.bx] == 'O') {
						blueflag = true;
						nb = { 0,0 };
					}
					else if (map[i][cur.bx] == '#' || (i == nr.first && cur.bx == nr.second)) break;
					else nb = { i,cur.bx };
				}
				//빨간구슬 먼저 이동
				for (int i = cur.ry - 1; i >= 0; i--) {
					if (map[i][cur.rx] == 'O') redflag = true;
					else if (map[i][cur.rx] == '#' || (i == nb.first && cur.rx == nb.second)) break;
					else nr = { i,cur.rx };
				}
			}
			if (redflag == true && blueflag == false) return cur.cnt + 1;
			if (blueflag != true) {
				node next = { nr.first,nr.second,nb.first,nb.second,cur.cnt + 1 };
				if ((chk[next.ry][next.rx][next.by][next.bx] == 0) && next.cnt <= 9) {
					q.push(next);
					chk[next.ry][next.rx][next.by][next.bx] = 1;
				}
			}
		}
		nr = { cur.ry,cur.rx };
		nb = { cur.by,cur.bx };
		//우
		if (map[cur.ry][cur.rx + 1] != '#' || map[cur.by][cur.bx + 1] != '#') {
			bool redflag = false, blueflag = false;
			if (cur.rx >= cur.bx) {
				//빨간구슬 이동
				for (int i = cur.rx + 1; i < m; i++) {
					if (map[cur.ry][i] == 'O') {
						redflag = true;
						nr = { 0,0 };
					}
					else if (map[cur.ry][i] == '#' || (cur.ry == nb.first && i == nb.second)) break;
					else nr = { cur.ry,i };
				}
				//파란구슬 이동
				for (int i = cur.bx + 1; i < m; i++) {
					if (map[cur.by][i] == 'O') blueflag = true;
					else if (map[cur.by][i] == '#' || (cur.by == nr.first && i == nr.second)) break;
					else nb = { cur.by,i };
				}
			}
			else {
				//파란구슬 이동
				for (int i = cur.bx + 1; i < m; i++) {
					if (map[cur.by][i] == 'O') {
						blueflag = true;
						nb = { 0,0 };
					}
					else if (map[cur.by][i] == '#' || (cur.by == nr.first && i == nr.second)) break;
					else nb = { cur.by,i };
				}
				//빨간구슬 이동
				for (int i = cur.rx + 1; i < m; i++) {
					if (map[cur.ry][i] == 'O') redflag = true;
					else if (map[cur.ry][i] == '#' || (cur.ry == nb.first && i == nb.second)) break;
					else nr = { cur.ry,i };
				}
			}
			if (redflag == true && blueflag == false) return cur.cnt + 1;
			if (blueflag != true) {
				node next = { nr.first,nr.second,nb.first,nb.second,cur.cnt + 1 };
				if ((chk[next.ry][next.rx][next.by][next.bx] == 0) && next.cnt <= 9) {
					q.push(next);
					chk[next.ry][next.rx][next.by][next.bx] = 1;
				}
			}
		}
		nr = { cur.ry,cur.rx };
		nb = { cur.by,cur.bx };
		//하
		if (map[cur.ry + 1][cur.rx] != '#' || map[cur.by + 1][cur.bx] != '#') {
			bool redflag = false, blueflag = false;
			if (cur.ry >= cur.by) {
				//빨간구슬 이동
				for (int i = cur.ry + 1; i < n; i++) {
					if (map[i][cur.rx] == 'O') {
						redflag = true;
						nr = { 0,0 };
					}
					else if (map[i][cur.rx] == '#' || (i == nb.first && cur.rx == nb.second)) break;
					else nr = { i,cur.rx };
				}
				//파란구슬 이동
				for (int i = cur.by + 1; i < n; i++) {
					if (map[i][cur.bx] == 'O') blueflag = true;
					else if (map[i][cur.bx] == '#' || (i == nr.first && cur.bx == nr.second)) break;
					else nb = { i,cur.bx };
				}
			}
			else {
				//파란구슬 이동
				for (int i = cur.by + 1; i < n; i++) {
					if (map[i][cur.bx] == 'O') {
						blueflag = true;
						nb = { 0,0 };
					}
					else if (map[i][cur.bx] == '#' || (i == nr.first && cur.bx == nr.second)) break;
					else nb = { i,cur.bx };
				}
				//빨간구슬 이동
				for (int i = cur.ry + 1; i < n; i++) {
					if (map[i][cur.rx] == 'O') redflag = true;
					else if (map[i][cur.rx] == '#' || (i == nb.first && cur.rx == nb.second)) break;
					else nr = { i,cur.rx };
				}
			}
			if (redflag == true && blueflag == false) return cur.cnt + 1;
			if (blueflag != true) {
				node next = { nr.first,nr.second,nb.first,nb.second,cur.cnt + 1 };
				if ((chk[next.ry][next.rx][next.by][next.bx] == 0) && next.cnt <= 9) {
					q.push(next);
					chk[next.ry][next.rx][next.by][next.bx] = 1;
				}
			}
		}
		nr = { cur.ry,cur.rx };
		nb = { cur.by,cur.bx };
		//좌
		if (map[cur.ry][cur.rx - 1] != '#' || map[cur.by][cur.bx - 1] != '#') {
			bool redflag = false, blueflag = false;
			if (cur.rx <= cur.bx) {
				//빨간구슬 이동
				for (int i = cur.rx - 1; i >= 0; i--) {
					if (map[cur.ry][i] == 'O') {
						redflag = true;
						nr = { 0,0 };
					}
					else if (map[cur.ry][i] == '#' || (cur.ry == nb.first && i == nb.second)) break;
					else nr = { cur.ry,i };
				}
				//파란구슬 이동
				for (int i = cur.bx - 1; i >= 0; i--) {
					if (map[cur.by][i] == 'O') blueflag = true;
					else if (map[cur.by][i] == '#' || (cur.by == nr.first&& i == nr.second)) break;
					else nb = { cur.by,i };
				}
			}
			else {
				//파란구슬 이동
				for (int i = cur.bx - 1; i >= 0; i--) {
					if (map[cur.by][i] == 'O') {
						blueflag = true;
						nb = { 0,0 };
					}
					else if (map[cur.by][i] == '#' || (cur.by == nr.first && i == nr.second)) break;
					else nb = { cur.by,i };
				}
				//빨간구슬 이동
				for (int i = cur.rx - 1; i >= 0; i--) {
					if (map[cur.ry][i] == 'O') redflag = true;
					else if (map[cur.ry][i] == '#' || (cur.ry == nb.first && i == nb.second)) break;
					else nr = { cur.ry,i };
				}
			}
			if (redflag == true && blueflag == false) return cur.cnt + 1;
			if (blueflag != true) {
				node next = { nr.first,nr.second,nb.first,nb.second,cur.cnt + 1 };
				if ((chk[next.ry][next.rx][next.by][next.bx] == 0) && next.cnt <= 9) {
					q.push(next);
					chk[next.ry][next.rx][next.by][next.bx] = 1;
				}
			}
		}
	}
	return -1;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == '#') chk[i][j][i][j] = 1;
			else if (map[i][j] == 'O') des = { i,j };
			else if (map[i][j] == 'R') r = { i,j };
			else if (map[i][j] == 'B') b = { i,j };
		}
	}
	printf("%d", bfs());
	return 0;
}