#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll dp[101][21];
int main() {
	int x, n; cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	dp[0][v[0]] = 1;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j] > 0) {
				if (j + v[i] <= 20) dp[i][j + v[i]] += dp[i - 1][j];
				if (0 <= j - v[i]) dp[i][j - v[i]] += dp[i - 1][j];
			}
		}
	}
	cout << dp[n - 2][v[n-1]];
	return 0;
}