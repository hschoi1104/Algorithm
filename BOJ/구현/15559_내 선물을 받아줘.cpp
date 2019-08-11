#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
int map[1001][1001];
int chk[1001][1001];
int dir[4][2] = { {-1,0} ,{1,0},{0,-1},{0,1} };

int ctoi(char c) {
	if (c == 'N') return 0;
	else if (c == 'S') return 1;
	else if (c == 'W') return 2;
	else return 3;
}

int main() {
	int n, m, ans = 0;
	char ch;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %1c", &ch);
			map[i][j] = ctoi(ch);
		}
	}
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (chk[i][j] == 0) {
				int y = i;
				int x = j;
				while (chk[y][x] == 0) {
					chk[y][x] = cnt;
					int d = map[y][x];
					y = y + dir[d][0];
					x = x + dir[d][1];
				}
				if (chk[y][x] == cnt) ans += 1;
				cnt++;
			}
		}
	}
	printf("%d", ans);
	return 0;
}