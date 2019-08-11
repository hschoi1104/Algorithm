#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll>km, cost;
ll ans = 0;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n; cin >> n;
	km.resize(n - 1); cost.resize(n);
	for (int i = 0; i < n - 1; i++) cin >> km[i];
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
		if (i != 0) cost[i] = min(cost[i], cost[i - 1]);
	}
	for (int i = 0; i < n-1; i++) ans += cost[i] * km[i];
	cout << ans;
	return 0;
}