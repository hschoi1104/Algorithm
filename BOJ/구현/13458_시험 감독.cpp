#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<int>v;
ll ans = 0;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x; v.push_back(x);
	}
	int a, b; cin >> a >> b;
	for (int i = 0; i < n; i++) {
		ans += 1; v[i] -= a;
		if (v[i] > 0) {
			if(v[i]/b==0) ans+=v[i]/b;
			else ans += v[i] / b + 1;
		}
	}
	cout << ans;
	return 0;
}