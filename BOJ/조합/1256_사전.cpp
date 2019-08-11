#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int dp[201][201];
string ans;
int main() {
	int n, m, k; cin >> n >> m >> k;
	for (int i = 0; i < 201; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			dp[i][j] = min(dp[i - 1][j - 1] + dp[i - 1][j], 1000000000);
		}
	}

	int tot = n + m;
	if (k > dp[tot][n]) cout << -1;
	else {
		for (int i = 0; i < tot; i++) {
			if (k > dp[n + m - 1][m]) {
				ans += 'z';
				k -= dp[n + m - 1][m];
				m--;
			}
			else {
				ans += 'a';
				n--;
			}
		}
	}
	cout << ans;
	return 0;
}