#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FORIJ(a,b) for(int i=a;i<b;i++) for(int j=a;j<b;j++)
using namespace std;
int n, l, r, arr[51][51], chk[51][51], dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} }, cnt[3010], cnt2[3010];
struct pos { int y, x; };
queue<pos>q;
void go(int y, int x, int num) {
	chk[y][x] = num;
	q.push({ y, x });
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = cur.y + dir[k][0], nx = cur.x + dir[k][1];
			if (0 <= ny && ny < n && 0 <= nx && nx < n && !chk[ny][nx]) {
				int val = abs(arr[ny][nx] - arr[cur.y][cur.x]);
				if (l <= val && val <= r) {
					chk[ny][nx] = num;
					q.push({ ny,nx });
				}
			}
		}
	}
	return;
}
int solve() {
	int ans = 0, num = 1;
	while (1) {
		memset(chk, 0, sizeof(chk));
		num = 1;
		if (ans >= 2000) return 0;
		FORIJ(0, n) {
			if (chk[i][j] == 0) {
				go(i, j, num);
				num += 1;
			}
		}

		if (num == n * n + 1) return ans;
		else {
			ans += 1;
			memset(cnt, 0, sizeof(cnt)); memset(cnt2, 0, sizeof(cnt2));
			FORIJ(0, n) {
				cnt[chk[i][j]] += arr[i][j];
				cnt2[chk[i][j]] += 1;
			}
			FORIJ(0, n) arr[i][j] = cnt[chk[i][j]] / cnt2[chk[i][j]];
		}
	}
	return ans;
}
int main() {
	FIO;
	cin >> n >> l >> r;
	FORIJ(0, n) cin >> arr[i][j];
	cout << solve();
	return 0;
}