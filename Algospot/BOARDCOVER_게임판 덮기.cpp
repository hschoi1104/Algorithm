#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int map[21][21];
int h, w;
int dir[4][3][2] = {
   {{0,0},{1,0},{1,-1}},
   {{0,0},{1,0},{1,1}},
   {{0,0},{1,0},{0,1}},
   {{0,0},{0,1},{1,1}}
};
void init() {
	memset(map, 0, sizeof(map));
}
int go() {
	int y = -1, x = -1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			if (map[i][j] == 0) {
				y = i; x = j;
				break;
			}
		if (y != -1) break;
	}
	if (y == -1) return 1;
	int ret = 0;

	for (int k = 0; k < 4; k++) {
		int cnt = 0;
		for (int p = 0; p < 3; p++) {
			if (y + dir[k][p][0] >= 0 && y + dir[k][p][0] < h && x + dir[k][p][1] >= 0 && x + dir[k][p][1] < w)
				if (map[y + dir[k][p][0]][x + dir[k][p][1]] == 0) cnt += 1;
		}
		if (cnt == 3) {
			for (int p = 0; p < 3; p++)   map[y + dir[k][p][0]][x + dir[k][p][1]] = 1;
			ret += go();
			for (int p = 0; p < 3; p++) map[y + dir[k][p][0]][x + dir[k][p][1]] = 0;
		}
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int c; cin >> c;
	while (c--) {
		init();
		cin >> h >> w;
		for (int i = 0; i < h; i++) {
			string s; cin >> s;
			for (int j = 0; j < s.length(); j++) {
				if (s[j] == '#') map[i][j] = 1;
				else map[i][j] = 0;
			}
		}
		cout << go() << "\n";
	}
	return 0;
}