#include <iostream>
#include <queue>
using namespace std;
int map[16][16], n;
typedef struct Point {
	int y1, x1, y2, x2;
}point;
int ans = 0, dir[3][2] = { {0,1},{1,1},{1,0} };//가로,대각,세로
queue<point>q;
bool chk(point s, int f) {
	if (s.x2 >= n || s.y2 >= n) return false;
	if (f == 1 && !map[s.y1][s.x1] && !map[s.y2][s.x2] && !map[s.y1][s.x2] && !map[s.y2][s.x1]) return true;
	if (f != 1 && !map[s.y1][s.x1] && !map[s.y2][s.x2]) return true;
	return false;
}
int bfs() {
	q.push(point{ 0,0,0,1 });
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		if (cur.y2 == n - 1 && cur.x2 == n - 1) {
			ans += 1;
			continue;
		}
		point next = point{ cur.y2,cur.x2,0,0 };
		//가로
		if (cur.y1 == cur.y2) {
			for (int k = 0; k <= 1; k++) {
				next.y2 = cur.y2 + dir[k][0];
				next.x2 = cur.x2 + dir[k][1];
				if (chk(next, k)) q.push(next);
			}
		}
		//세로
		else if (cur.x1 == cur.x2) {
			for (int k = 1; k <= 2; k++) {
				next.y2 = cur.y2 + dir[k][0];
				next.x2 = cur.x2 + dir[k][1];
				if (chk(next, k)) q.push(next);
			}
		}
		//대각
		else if (cur.x1 != cur.x2 && cur.y1 != cur.y2) {
			for (int k = 0; k <= 2; k++) {
				next.y2 = cur.y2 + dir[k][0];
				next.x2 = cur.x2 + dir[k][1];
				if (chk(next, k)) q.push(next);
			}
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> map[i][j];
	cout << bfs();
	return 0;
}