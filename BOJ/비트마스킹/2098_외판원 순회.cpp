#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 1e8
using namespace std;
int n, arr[16][16], dp[16][1 << 16];
int tsp(int cur, int num) {
	int& ret = dp[cur][num];
	if (ret != -1) return ret;
	if (num == (1 << n) - 1) {
		if (arr[cur][0] != 0) return arr[cur][0];
		return INF;
	}
	ret = INF;
	for (int i = 1; i < n; i++) if (!(num & (1 << i)) && arr[cur][i] != 0) 	ret = min(ret, tsp(i, num | (1 << i)) + arr[cur][i]);
	return ret;
}
int main() {
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> arr[i][j];
	for (int i = 0; i < n; i++) fill(begin(dp[i]), end(dp[i]), -1);
	cout << tsp(0, 1);
	return 0;
}