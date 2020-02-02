#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
using namespace std;
typedef struct pi {
	int r, c, s;
};
vector<pi>v;
int n, m, k, ans = INT_MAX, map[51][51], tmap[51][51], ttmap[51][51], chk[6];
void copy() {
	for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++) tmap[i][j] = map[i][j];
	return;
}
void cal() {
	int res = INT_MAX;
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		for (int j = 1; j <= m; j++) {
			tmp += tmap[i][j];
		}
		res = min(res, tmp);
	}
	ans = min(ans, res);
	return;
}
void go(pi it) {
	int t = 1;
	ttmap[it.r][it.c] = tmap[it.r][it.c];
	while (t <= it.s) {
		//À§
		for (int x = it.c - t; x < it.c - t + 2 * t; x++) ttmap[it.r - t][x + 1] = tmap[it.r - t][x];
		//¾Æ
		for (int x = it.c + t; x > it.c + t - 2 * t; x--) ttmap[it.r + t][x -1] = tmap[it.r + t][x];
		//¿À
		for (int y = it.r - t; y < it.r - t + 2 * t; y++) ttmap[y+1][it.c+t] = tmap[y][it.c+t];
		//¿Þ
		for (int y = it.r + t; y > it.r + t - 2 * t; y--) ttmap[y-1][it.c-t] = tmap[y][it.c-t];
		t++;
	}
	for (int i = it.r - it.s; i <= it.r + it.s; i++) for (int j = it.c - it.s; j <= it.c + it.s; j++) tmap[i][j] = ttmap[i][j];
	return;
}
void per(int pos) {
	if (pos == k+1) {
		copy();
		for(int i=0;i<k;i++){
			go(v[chk[i]-1]);
		}
		cal();
		return;
	}
	for (int i = 0; i < k; i++) {
		if (!chk[i]) {
			chk[i] = pos;
			per(pos + 1);
			chk[i] = 0;
		}
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> map[i][j];
	for (int i = 0; i < k; i++) {
		pi tmp; cin >> tmp.r >> tmp.c >> tmp.s;
		v.push_back(tmp);
	}
	per(1);
	cout << ans;
	return 0;
}