#include <stdio.h>
#include <algorithm>
#include <string.h>
#define INT_MA 100000000
using namespace std;
int arr[16][16];
int dp[16][1 << 16];
int n;

int go(int cur, int visited) {
	int &ret = dp[cur][visited];
	if (ret != -1)return ret;
	//다방문했을경우
	if (visited == (1 << n) - 1) {
		if (arr[cur][0] != 0) return arr[cur][0];
		return INT_MA;
	}
	ret = INT_MA;
	//방문할곳이 남은경우
	for (int i = 0; i < n; i++) {
		if ((visited&(1 << i))!=0 || arr[cur][i]==0) continue;
		ret = min(ret, go(i, visited | (1 << i)) + arr[cur][i]);
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < 16; i++) {
		memset(dp[i], -1, sizeof(dp[i]));
	}
	printf("%d\n", go(0, 1));
	return 0;
}