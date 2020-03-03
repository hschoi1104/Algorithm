#include <iostream>
#include <string.h>
using namespace std;
int dp[1001];
int go(int n) {
	int& ret = dp[n];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < n; ++i) {
		if (((n - i) / 2) * 2 + i == n) ret += go((n - i) / 2);
	}
	return ret += 1;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	memset(dp, -1, sizeof(dp));
	dp[0] = 0; dp[1] = 1; dp[2] = dp[3] = 2;
	while (t--) {
		int n; cin >> n;
		cout << go(n) << "\n";
	}
}