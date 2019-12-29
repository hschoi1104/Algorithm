#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int dp1[50], dp2[50], siz, pos;
int go1(int n) {
	int& ret = dp1[n];
	if (ret != -1) return ret;
	return ret = go1(n - 1) + go1(n - 2);
}
int go2(int n) {
	int& ret = dp2[n];
	if (ret != -1) return ret;
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += go1(i);
	}
	return ret = go2(n - 1) + go2(n - 2) + res;
}
int main() {
	cin >> siz >> pos;
	memset(dp1, -1, sizeof(dp1));
	memset(dp2, -1, sizeof(dp2));
	dp1[0] = 0, dp1[1] = 1, dp1[2] = 2, dp1[3] = 3, dp1[4] = 5;
	dp2[0] = 0, dp2[1] = 0, dp2[2] = 2, dp2[3] = 6, dp2[4] = 14;
	if (pos == 1 | pos == siz) cout << go2(siz);
	else cout << go2(pos) * go1(siz - pos) + go1(pos - 1) * go2(siz - pos + 1) - go1(pos - 1) * go1(siz - pos);
	return 0;
}