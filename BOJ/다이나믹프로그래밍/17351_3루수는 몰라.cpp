#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
char arr[501][501];
int dp[501][501];
string str = "MOLA";
int go(int y, int x, int cnt) {
	if (!y || !x) return 0;
	if (arr[y][x] == str[cnt]) {
		if (!cnt) return dp[y][x] + 1;
		return max(go(y - 1, x, cnt - 1), go(y, x - 1, cnt - 1));
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		for (int j = 1; j <= n; j++) {
			arr[i][j] = s[j - 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = max(dp[i - 1][j], max(dp[i][j - 1], go(i, j, 3)));
		}
	}
	cout << dp[n][n];
	return 0;
}