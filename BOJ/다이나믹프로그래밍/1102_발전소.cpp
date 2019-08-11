#include<iostream>
#include<vector>
#include<string>
#include <string.h>
#include <algorithm>
#define INF 999999999
using namespace std;
int arr[16][16];
int dp[1 << 16];
string onoff;
int n, p;
int go(int cnt, int on) {
	if (cnt >= p) return 0;

	int& ret = dp[on];
	if (ret != -1) return ret;
	ret = INF;

	for (int i = 0; i < n; i++) {
		if (on & (1 << i)) {
			for (int j = 0; j < n; j++) {
				if (on & (1 << j)) continue;
				ret = min(ret, go(cnt + 1, on | (1 << j)) + arr[i][j]);
			}
		}
	}
	return ret;
}
int main() {
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> arr[i][j];
	cin >> onoff >> p;
	int cnt = 0, on=0;
	for(int i=0;i<onoff.length();i++){
		if (onoff[i] == 'Y') {
			cnt += 1;
			on |= (1 << i);
		}
	}
	int ret = go(cnt, on);
	if (ret == INF) cout << -1;
	else cout << ret;
	return 0;
}