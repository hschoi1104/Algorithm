#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(a, b) for(int i=a;i<b;i++)
#define p pair<int,int>
using namespace std;
set<p>s;
int n, k, x, cnt[101], ans;
vector<int>v;
int main() {
	FIO;
	cin >> n >> k;
	FOR(0, k) {
		cin >> x; v.push_back(x);
	}

	for (int j = v.size() - 1; j >= 0; j--) {
		int pos = j - 1;
		while (1) {
			if (pos < 0) break;
			if (v[j] == v[pos]) {
				cnt[pos] = j;
				break;
			}
			pos--;
		}
		cnt[j] = (!cnt[j] ? INT_MIN : cnt[j]);
	}

	FOR(0, k) {
		int val = v[i];
		auto target = find_if(s.begin(), s.end(), [&val](const pair<int, int>& tmp) { return tmp.second == val; });
		if (s.size() < n) {
			if (target != s.end()) s.erase(target);
			s.insert({ -cnt[i],v[i] });
			continue;
		}
		if (target == s.end()) {
			ans += 1;
			s.erase(s.begin());
		}
		else s.erase(target);
		s.insert({ -cnt[i],v[i] });
	}
	cout << ans;
	return 0;
}