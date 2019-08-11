#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
vector <ll> ans;
int chk[7501];
ll val[7501];
ll n, k;
ll getdist(ll x, ll y) {
	if (y < x) swap(x, y);
	return (2019201913 * x + 2019201949 * y) % 2019201997;
}
void prim() {
	for (int i = 1; i <= n; i++) ans[i] = 2019201996;
	for (int i = 1; i <= n; i++) {
		int minIndex = 0;
		for (int j = 1; j <= n; j++) {
			if (chk[j] == 0 && (minIndex == 0 || ans[minIndex] > ans[j])) minIndex = j;
		}
		chk[minIndex] = 1;
		for (int j = 1; j <= n; j++) {
			if (chk[j] == 0) ans[j] = min(ans[j], getdist(minIndex, j));
		}
	}
	return;
}
int main() {
	cin >> n >> k;
	ans.resize(n + 1);
	prim();
	sort(ans.begin(), ans.end());
	cout << ans[n - k + 1];
	return 0;
}