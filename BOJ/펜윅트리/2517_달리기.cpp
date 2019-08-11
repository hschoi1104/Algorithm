#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>p;
vector<p>input;
vector<int>ans;
vector<ll>t;
vector<ll>v;
ll x;
int h = 1;
ll sum(int i) {
	ll res = 0;
	while (i > 0) {
		res += t[i];
		i -= (i & -i);
	}
	return res;
}
void update(ll i, ll val) {
	while (i < t.size()) {
		t[i] += val;
		i += (i & -i);
	}
}
bool cmp(p a, p b) {
	if (a.second < b.second) return true;
	else if (a.second == b.second)
		return a.first < b.first;
	else return false;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	t.resize(n + 1);
	v.resize(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> x;
		input.push_back({ x,i });
	}
	sort(input.begin(), input.end());
	for (int i = 0; i < input.size(); i++) {
		input[i].first = i;
	}
	sort(input.begin(), input.end(), cmp);
	for (int i = 0; i < n; i++) {
		input[i].first = n - input[i].first;
	}
	for (int i = 0; i < input.size(); i++) {
		ll diff = 1 - v[input[i].first];
		v[input[i].first] = 1;
		ans.push_back(sum(input[i].first));
		update(input[i].first, diff);
	}

	for (auto it : ans) {
		cout << it + 1 << "\n";
	}
	return 0;
}