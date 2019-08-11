#include <stdio.h>
#include <algorithm>
#include <utility>
#include <limits.h>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>p;
multimap<ll, bool>line;
ll arr[100001];
int ans = 1;
int main() {
	ll n, m;
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; i++) {
		ll x, y;
		scanf("%lld %lld", &x, &y);
		arr[i] = x + y * m;
	}
	line.insert({ arr[n - 1],1 });
	for (int i = n - 2; i >= 0; i--) {
		bool flag = false;
		for (auto it = line.begin(); it != line.end(); it++) {
			if (it->first <= arr[i]) continue;
			else {
				line.erase(it);
				line.insert({ arr[i], 1 });
				flag = true;
				break;
			}
		}
		if (flag == false) line.insert({ arr[i],true });
	}
	printf("%d", line.size());
	return 0;
}