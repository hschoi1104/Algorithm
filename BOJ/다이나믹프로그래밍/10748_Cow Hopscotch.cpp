#include<stdio.h>
#include <string.h>
using namespace std;
typedef long long ll;
ll arr[101][101];
ll dp[101][101];
int r, c, k;
ll go(int y, int x, ll num) {
	ll &ret = dp[y][x];
	if (ret != -1) return ret;
	ret = 0;
	if (num != arr[r - 1][c - 1]) {
		ret += 1;
		if (y == r - 2 || x == c - 2) return ret% 1000000007;
	}

	for (int i = y + 1; i < r - 1; i++) {
		for (int j = x + 1; j < c - 1; j++) {
			if (arr[i][j] != num) {
				ret += go(i, j, arr[i][j])% 1000000007;
			}
		}
	}
	return ret% 1000000007;
}
int main() {
	scanf("%d %d %d", &r, &c, &k);
	for (int i = 0; i < 101; i++) {
		memset(dp[i], -1, sizeof(dp[i]));
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%lld", &arr[i][j]);
		}
	}
	go(0, 0, arr[0][0]);
	printf("%lld", dp[0][0]% 1000000007);
	return 0;
}