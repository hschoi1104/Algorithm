#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
typedef pair<int, int> p;
int dp[301][301], weight[301][301];
int arr[301], chk[301];
vector<p> v;
int n, m, k, t;
int go(int x, int y) {
	if (x == v.size()) return 0;
	int& ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 0;
	for (int j = 0; j <= k - y; j++) {
		ret = max(ret, go(x + 1, y + j) + weight[x][j]);
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k >> t;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		for (int j = a; j < b; j++) arr[j] += 1;
	}
	int r = 0;
	for (int i = 1; i <= n; i++) {
		if (chk[i] == 0 && arr[i] < t) {
			int s = i;
			while (arr[i] < t && i <= n) i++;
			v.push_back({ s,i - 1 });
		}
		if (arr[i] >= t)r += 1;
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = 1; j <= k; j++) {
			int temp = 0;
			for (int p = v[i].first; p <= v[i].second; p++) {
				if (arr[p] + j >= t) temp += 1;
			}
			weight[i][j] = temp;
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << go(0, 0) + r;
	return 0;
}