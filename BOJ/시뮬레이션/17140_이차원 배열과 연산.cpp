#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int r, c, k, arr[110][110], max_r, max_c, chk[101];
struct node {
	int num, cnt;
	bool operator <(const node& tmp)const {
		if (cnt == tmp.cnt) return num < tmp.num;
		else return cnt < tmp.cnt;
	}
};
vector<node>v;
void init() {
	memset(chk, 0, sizeof(chk));
	v.clear();
	return;
}
void C() {
	int tmp_r = 0;
	for (int i = 0; i < max_c; i++) {
		init();
		for (int j = 0; j < max_r; j++) chk[arr[j][i]] += 1;
		for (int j = 1; j < 101; j++) if (chk[j]) v.push_back({ j,chk[j] });
		sort(v.begin(), v.end());
		for (int j = 0; j < 100; j += 2) {
			if (j == 0) {
				arr[j][i] = v[0].num;
				arr[j + 1][i] = v[0].cnt;
				tmp_r = max(tmp_r, j + 2);
			}
			else if (j / 2 < v.size()) {
				arr[j][i] = v[j / 2].num;
				arr[j + 1][i] = v[j / 2].cnt;
				tmp_r = max(tmp_r, j + 2);
			}
			else {
				arr[j][i] = arr[j + 1][i] = 0;
			}
		}
	}
	max_r = tmp_r;
	return;
}
void R() {
	int tmp_c = 0;
	for (int i = 0; i < max_r; i++) {
		init();
		for (int j = 0; j < max_c; j++) chk[arr[i][j]] += 1;
		for (int j = 1; j < 101; j++) if (chk[j]) v.push_back({ j,chk[j] });
		sort(v.begin(), v.end());
		for (int j = 0; j < 100; j += 2) {
			if (j == 0) {
				arr[i][j] = v[0].num;
				arr[i][j + 1] = v[0].cnt;
				tmp_c = max(tmp_c, j + 2);
			}
			else if (j / 2 < v.size()) {
				arr[i][j] = v[j / 2].num;
				arr[i][j + 1] = v[j / 2].cnt;
				tmp_c = max(tmp_c, j + 2);
			}
			else {
				arr[i][j] = arr[i][j + 1] = 0;
			}
		}
	}
	max_c = tmp_c;
	return;
}
int solve() {
	if (arr[r][c] == k) return 0;
	int t = 100;
	while (t--) {
		//r연산
		if (max_r >= max_c) R();
		//c연산
		else C();

		if (arr[r][c] == k) return 100 - t;
	}
	return -1;
}

int main() {
	FIO;
	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) cin >> arr[i][j];
	r -= 1; c -= 1;
	max_r = max_c = 3;

	cout << solve();
	return 0;
}