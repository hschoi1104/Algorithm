#include <iostream>
using namespace std;
int dp[31][31];
int go(int nn, int kk) {
	if (nn == kk) return 1;
	if (kk == 0) return 1;
	if (kk == 1) return nn;
	int& ret = dp[nn][kk];
	if (ret != -1) return ret;
	ret = 0;
	return ret = go(nn - 1, kk - 1) + go(nn - 1, kk);
}
int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		for (int i = 0; i <= 30; i++) {
			for (int j = 0; j <= 30; j++) {
				dp[i][j] = -1;
			}
		}
		cout << go(k, n)<<"\n";
	}
	return 0;
}