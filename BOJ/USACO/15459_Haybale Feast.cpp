#include <iostream>
#include <vector>
#include <algorithm>
#define max_right 1000000000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
vector<p> v;
ll a, b, n, m, l = 0, r = max_right, ans = max_right;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a >> b, v.push_back({ a,b });

	while (l <= r) {
		ll mid = (l + r) / 2;
		bool flag = false;
		ll temp = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].second <= mid)	temp += v[i].first;
			else temp = 0;

			if (temp >= m) {
				flag = true;
				ans = min(ans, mid);
				break;
			}
		}
		if (!flag) l = mid + 1;
		else r = mid - 1;
	}
	cout << ans;
	return 0;
}