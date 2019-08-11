#include <stdio.h>
#include <algorithm>
#include <utility>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>p;
p arr[100001];
int ans = 1;
int main() {
	ll n, m;
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &arr[i].first, &arr[i].second);
	}
	ll minpos = arr[n - 1].first + arr[n - 1].second*m;
	for (int i = n - 2; i >= 0; i--) {
		if (arr[i].first + arr[i].second*m > arr[i + 1].first + arr[i + 1].second*m) continue;
		else if (arr[i].first+arr[i].second*m < minpos) {
			ans += 1;
			minpos = arr[i].first + arr[i].second*m;
		}
	}
	printf("%d", ans);
	return 0;
}