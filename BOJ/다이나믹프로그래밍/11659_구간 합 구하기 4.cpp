#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll>v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll a,b,x, n, m; cin >> n >> m;
	v.push_back(0);
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	for (int i = 1; i < v.size(); i++) v[i] += v[i - 1];
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << v[b] - v[a - 1]<<"\n";
	}
	return 0;
}