#include <stdio.h>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
typedef long long ll;
priority_queue<ll,vector<ll>,greater<ll>>pq;
int main() {
	int n, m;
	ll x;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &x);
		pq.push(x);
	}
	while (m--) {
		ll sum = pq.top();  pq.pop();
		sum += pq.top(); pq.pop();
		pq.push(sum); pq.push(sum);
	}
	ll ans = 0;
	while (!pq.empty()) {
		ans += pq.top(); pq.pop();
	}
	printf("%lld", ans);
	return 0;
}