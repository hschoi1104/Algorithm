#include <stdio.h>
#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
vector<ll>dist;
vector<ll>value;
vector<ll>cnt;
vector<ll>cost;
vector<ll>v;

ll distsum(int i) {
	ll res = 0;
	while (i > 0) {
		res += dist[i];
		i -= (i & -i);
	}
	return res;
}
void distupdate(int i, ll val) {
	while (i < dist.size()) {
		dist[i] += val;
		i += (i & -i);
	}
}
ll cntsum(int i) {
	ll res = 0;
	while (i > 0) {
		res += cnt[i];
		i -= (i & -i);
	}
	return res;
}
void cntupdate(int i, ll val) {
	while (i < cnt.size()) {
		cnt[i] += val;
		i += (i & -i);
	}
}
int main() {
	int n;
	ll ans = 0;
	scanf("%d", &n);
	dist.resize(200002);
	cnt.resize(200002);
	v.resize(n + 2);
	cost.resize(n + 2);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
		v[i] += 1;
		if (i == 1) {
			cntupdate(v[i], 1);
			distupdate(v[i], v[i]);
			continue;
		}
		else {
			ans = 0;
			//현재 좌표보다 작은 부분
			ans = v[i] * cntsum(v[i]) - distsum(v[i]);
			//현재 좌표보다 큰 부분
			ans += distsum(200001)-distsum(v[i]-1) - (v[i] * (cntsum(200001) - cntsum(v[i]-1)));
			cost[i] = ans % MOD;
			distupdate(v[i], v[i]);
			cntupdate(v[i], 1);
		}
	}
	ans = 1;
	for (int i = 2; i <= n; i++) {
		ans = (ans % MOD * cost[i] % MOD) % MOD;
	}
	printf("%lld", ans);
	return 0;
}