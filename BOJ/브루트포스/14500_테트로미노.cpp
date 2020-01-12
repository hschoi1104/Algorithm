#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, map[501][501], ans = 0;
int arr[8][4][2] = { { {0,0},{1,0},{2,0},{2,1} },{{0,1},{1,1},{2,1},{2,0} },{{0,0},{1,0},{2,0},{0,1} },{{0,0},{0,1},{1,1},{2,1} },{{0,0},{1,0},{1,1},{2,1}},{{0,1},{1,1},{1,0},{2,0}},{{0,0},{1,0},{2,0},{1,1}},{{1,0},{0,1},{1,1},{2,1}} };
int brr[8][4][2] = { {{0,0},{0,1},{0,2},{1,0}},{{0,0},{0,1},{0,2},{1,2}},{{0,0},{0,1},{0,2},{1,1}},{{1,0},{1,1},{1,2},{0,0}}, {{1,0},{1,1},{1,2},{0,2}}, {{1,0},{1,1},{1,2},{0,1}},{{0,0},{0,1},{1,1},{1,2}},{{0,1},{0,2},{1,0},{1,1}} };
int crr[4][2] = { {0,0},{0,1},{0,2},{0,3} };
int drr[4][2] = { {0,0},{1,0},{2,0},{3,0} };
int frr[4][2] = { {0,0},{0,1},{1,0},{1,1} };
bool chk(int i, int j, int a, int b) {
	return (i + a <= n && j + b <= m) ? true : false;
}
void go(int i, int j) {

	if (chk(i, j, 1, 4)) {
		int cnt = 0;
		for (int p = 0; p < 4; p++) {
			cnt += map[i + crr[p][0]][j + crr[p][1]];
		}
		ans = max(cnt, ans);
	}
	if (chk(i, j, 4, 1)) {
		int cnt = 0;
		for (int p = 0; p < 4; p++) {
			cnt += map[i + drr[p][0]][j + drr[p][1]];
		}
		ans = max(cnt, ans);
	}
	if (chk(i, j, 2, 2)) {
		int cnt = 0;
		for (int p = 0; p < 4; p++) {
			cnt += map[i + frr[p][0]][j + frr[p][1]];
		}
		ans = max(cnt, ans);
	}
	if (chk(i, j, 2, 3)) {
		for (int p = 0; p < 8; p++) {
			int cnt = 0;
			for (int q = 0; q < 4; q++) {
				cnt += map[i + brr[p][q][0]][j + brr[p][q][1]];
			}
			ans = max(cnt, ans);
		}
		
	}
	if (chk(i, j, 3, 2)) {
		for (int p = 0; p < 8; p++) {
			int cnt = 0;
			for (int q = 0; q < 4; q++) {
				cnt += map[i + arr[p][q][0]][j + arr[p][q][1]];
			}
			ans = max(cnt, ans);
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> map[i][j];

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) go(i, j);
	
	cout << ans;
	return 0;
}