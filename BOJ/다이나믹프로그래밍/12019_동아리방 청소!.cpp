#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int n, m, x;
int arr[102], dp[102][12][102];
int go(int now, int cnt, int state, int dust) {
	if (now == n + 1) return 0;
	int& ret = dp[now][cnt][state];
	if (ret != -1) return ret;

	ret = go(now + 1, cnt, state, dust + arr[now]);
	if (cnt > 0) ret = min(ret, go(now + 1, cnt - 1, now, 0));

	return ret += arr[now] * dust;
}
void traceback(int cnt, int state) {
	for (int i = 1; i < n; i++) {
		if (!cnt) break;
		if (dp[i + 1][cnt][state] >= dp[i + 1][cnt - 1][i]) {
			state = i;
			cout << i << " ";
			cnt -= 1;
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> x;  arr[i] = x;
	}
	cout << go(1, m, 0, 0) << "\n";
	traceback(m, 0);
	return 0;
}