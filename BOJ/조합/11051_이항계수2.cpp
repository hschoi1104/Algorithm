#include <iostream>
#define MOD 10007
using namespace std;
int dp[1001][1001];
int go(int nn, int kk) {
	if (nn == kk) return 1;
	if (kk == 0) return 1;
	if (kk == 1) return nn;
	int& ret = dp[nn][kk];
	if (ret != -1) return ret;
	ret = 0;
	return ret = (go(nn - 1, kk - 1) % MOD + go(nn - 1, kk) % MOD) % MOD;
}
int main() {
	int n, k; cin >> n >> k;
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			dp[i][j] = -1;
		}
	}
	cout << go(n, k) % MOD;
	return 0;
}