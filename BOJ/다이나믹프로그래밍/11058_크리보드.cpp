﻿#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll dp[101];
int main() {
	ll n; cin >> n;
	for (int i = 0; i <= 6; i++)dp[i] = i;
	for (int i = 7; i <= 100; i++) {
		for (int j = 1; j <= i - 3; j++) {
			dp[i] = max(dp[i], max(dp[i - 1] + 1, dp[i - (j + 2)] * (j + 1)));
		}
	}
	cout << dp[n];
	return 0;
}