#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
int map[11][11], chk[11][11], chkp[6], ans = INT_MAX;
int count(int y, int x, int k) {
	int cnt = 0;
	for (int i = y; i < y + k; i++)for (int j = x; j < x + k; j++)if (map[i][j] && !chk[i][j]) cnt++;
	return cnt;
}
void chkmap(int y, int x, int k,bool flag) {
	if (flag) {
		for (int i = y; i < y + k; i++)for (int j = x; j < x + k; j++) chk[i][j] = 1;
	}
	else {
		for (int i = y; i < y + k; i++)for (int j = x; j < x + k; j++) chk[i][j] = 0;
	}
}
void go(int y, int x, int k,int cnt) {//y,x,남은1개수,배치한 종이 개수
	if (x > 9) {
		y += 1;
		x = 0;
	}
	if (k == 0) {
		ans = min(ans, cnt);
		return;
	}
	//현재 좌표에 1이 없거나 이미 본 좌표인경우 건너뜀
	if (!map[y][x] || chk[y][x]) go(y, x + 1, k, cnt);
	if(map[y][x] || !chk[y][x]){
		for (int i = 5; i >= 1; i--) {
		if (y + i > 10 || x + i > 10) continue;
		int tmp = count(y, x, i);
		if (tmp != i * i || chkp[i]>=5) continue;
		chkp[i] += 1;
		chkmap(y, x, i, 1);
		go(y, x + 1, k - tmp, cnt + 1);
		chkmap(y, x, i, 0);
		chkp[i] -= 1;
		}
	}
	return;
}
int main() {
	for (int i = 0; i < 10; i++)for (int j = 0; j < 10; j++) cin >> map[i][j];
	go(0,0,count(0,0,10),0);
	ans = (ans == INT_MAX) ? -1 : ans;
	cout << ans;
	return 0;
}