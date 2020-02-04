#include <iostream>
#include <vector>
#include <limits.h>
#include <string.h>
#include <algorithm>
using namespace std;
vector<vector<int>>v;
int n, t, x, ans = INT_MAX, val[3], ppl[11], chk[11], dfschk[11];
void dfs(int cur, int m) {
	for (int i = 0; i < v[cur].size(); i++) {
		int next = v[cur][i];
		if (!dfschk[next] && chk[next] == m) {
			dfschk[next] = m;
			val[m] += ppl[next];
			dfs(next, m);
		}
	}
	return;
}
bool check() {
	//선거구는 무조건 1개 부터 n-1개까지 두선거구의 합은 n
	int v1 = 0, v2 = 0;
	for (int i = 0; i < n; i++) {
		if (chk[i] == 1) v1 += 1;
		else v2 += 1;
	}
	if (!v1 || !v2 || v1 + v2 != n) return false;
	//각 선거구는 이어져야함
	memset(dfschk, 0, sizeof(dfschk));
	val[1] = val[2] = 0;
	//선거구 dfs
	for (int k = 1; k <= 2; k++) {
		for (int i = 0; i < n; i++) {
			if (chk[i] == k) {
				dfschk[i] = k;
				val[k] += ppl[i];
				dfs(i, k);
				break;
			}
		}
	}
	//조합으로 지정한 선거구와 dfs의 결과 비교
	for (int i = 0; i < n; i++) {
		if (chk[i] == dfschk[i]) continue;
		else return false;
	}
	return true;
}
void go(int pos) {
	if (pos == n) return;
	if (check()) ans = min(ans, abs(val[1] - val[2]));
	for (int i = 1; i <= 2; i++) {
		chk[pos] = i;
		go(pos + 1);
		chk[pos] = 2;
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n; v.resize(n + 1);
	for (int i = 0; i < n; i++) cin >> ppl[i];
	for (int i = 0; i < n; i++) {
		cin >> t;
		for (int j = 0; j < t; j++) {
			cin >> x;
			v[i].push_back(x - 1);
		}
	}
	for (int i = 0; i < n; i++) chk[i] = 2;
	go(0);
	ans = (ans == INT_MAX) ? -1 : ans;
	cout << ans;
	return 0;
}