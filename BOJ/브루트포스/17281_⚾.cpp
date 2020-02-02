#include <iostream>
#include <algorithm>
using namespace std;
int chk[10] = { 0,0,0,0,1 }, game[51][10], state[5], n, out = 0, ans = 0;
//주자들이 움직임
void init() {
	for (int i = 0; i < 5; i++) state[i] = 0;
	out = 0;
}
int move(int r) {
	int res = 0;
	state[0] = 1;
	for (int i = 3; i >= 0; i--) {
		if (state[i]) {
			if (i + r >= 4)	res += 1;
			else state[i + r] = 1;
			state[i] = 0;
		}
	}
	return res;
}
void cal() {
	int res = 0, t = n, pos = 1;
	for (int i = 0; i < n; i++) {//이닝
		while (1) {//선수들이 타석에 섬, out == 3까지
			if (out == 3) {
				init();
				break;
			}
			if (pos == 10) pos -= 9;
			if (!game[i][chk[pos]]) out += 1;
			else res += move(game[i][chk[pos]]);
			pos++;
		}
	}
	ans = max(ans, res);
}
void go(int pos) {
	if (pos == 10) {
		cal();
		return;
	}
	for (int i = 1; i <= 9; i++) {
		if (!chk[i]) {
			chk[i] = pos;
			go(pos + 1);
			chk[i] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 1; j <= 9; j++) cin >> game[i][j];
	go(2);
	cout << ans;
	return 0;
}