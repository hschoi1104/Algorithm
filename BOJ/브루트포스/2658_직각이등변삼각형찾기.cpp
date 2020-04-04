#include <stdio.h>
#include <algorithm>
using namespace std;
int dir[4][2] = { {-1,-1},{-1,1},{1,-1},{1,1} };
int dir2[4][2] = { {1,1},{-1,1},{1,1},{1,-1} };
int arr[11][11], ans, max_dep, cnt;
struct pos {
	int y, x;
	bool operator < (const pos& tmp) const {
		if (y == tmp.y) return x < tmp.x;
		else return y < tmp.y;
	}
};
pos p[3];

int go(int y, int x, int dep, int d) {
	int ny = y + dir[d][0] * dep, nx = x + dir[d][1] * dep;
	bool chk = true;
	if (0 <= ny && ny < 10 && 0 <= nx && nx < 10) {
		for (int i = min(x, nx); i <= max(x, nx); i++) {
			if (!arr[ny][i]) chk = false;
		}
	}
	else chk = false;
	if (chk) return max(dep, go(y, x, dep + 1, d));
	else return 0;
}
int go2(int y, int x, int dep, int d) {
	if (d == 0 || d == 1) {
		bool chk = true;
		if (0 <= x - dep * dir2[d][1] && x + dep * dir2[d][1] < 10 && 0 <= y + dep * dir[d][0] && y + dep * dir[d][0] < 10) {
			for (int i = x - dep * dir2[d][1]; i <= x + dep * dir2[d][1]; i++) {
				if (!arr[y + dep * dir2[d][0]][i]) chk = false;
			}
		}
		else chk = false;

		if (chk) return max(dep, go2(y, x, dep + 1, d));
		else return 0;
	}
	else {
		bool chk = true;
		if (0 <= x + dep * dir2[d][1] && x + dep * dir2[d][1] < 10 && 0 <= y - dep * dir[d][0] && y + dep * dir[d][0] < 10) {
			for (int i = y - dep * dir2[d][0]; i <= y + dep * dir2[d][0]; i++) {
				if (!arr[i][x + dep * dir2[d][1]]) chk = false;
			}
		}
		else chk = false;
		if (chk) return max(dep, go2(y, x, dep + 1, d));
		else return 0;
	}
}
int main() {
	for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) scanf("%1d", &arr[i][j]);

	for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) if (arr[i][j]) cnt += 1;

	for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) {
		if (arr[i][j]) {
			for (int k = 0; k < 4; k++) {
				int res = go(i, j, 1, k) + 1;
				if (ans < (res * res - res) / 2 + res) {
					ans = (res * res - res) / 2 + res;
					max_dep = res;
					p[0] = { i,j };
					p[1] = { i + (res - 1) * dir[k][0] , j };
					p[2] = { i + (res - 1) * dir[k][0] ,j + (res - 1) * dir[k][1] };
				}
			}
			for (int k = 0; k < 4; k++) {
				int res = go2(i, j, 1, k) + 1;
				if (ans < res * res) {
					ans = res * res;
					max_dep = res;
					p[0] = { i,j };
					if (k == 0 || k == 1) {
						p[1] = { i + (res - 1) * dir2[k][0],j + (res - 1) };
						p[2] = { i + (res - 1) * dir2[k][0],j - (res - 1) };
					}
					else {
						p[1] = { i + (res - 1),j + (res - 1) * dir2[k][1] };
						p[2] = { i - (res - 1),j + (res - 1) * dir2[k][1] };
					}
				}
			}
		}
	}
	sort(p, p + 3);
	if (ans != cnt) printf("%d", 0);
	else for (int i = 0; i < 3; i++) printf("%d %d\n", p[i].y + 1, p[i].x + 1);
	return 0;
}