#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>v;
int dp[201][201];
int main() {
	int x, n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> x; v.push_back(x);
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			dp[i][j] = 1e9;
			for (int k = i; k <= j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + (v[i] != v[j]));
			}
		}
	}
	cout << dp[0][n - 1];
	return 0;
}