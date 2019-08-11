#include <stdio.h>
using namespace std;
typedef long long ll;
int n, t;
ll c;
ll fac[21];
int arr[21];
int visited[21];
void go(int th, ll c) {
	int cnt = 1;
	for (ll i = 1; i <= (ll)n; i++) {
		if (visited[i] == 1) continue;
		else if (c > cnt*fac[th]) {
			cnt += 1;
			continue;
		}
		else {
			visited[i] = 1;
			arr[n - th] = i;
			go(th - 1, c-(cnt-1)*fac[th]);
		}
	}
	return;
}
ll goo(int th, ll ans) {
	if (th == -1)return ans + 1;
	int cnt = 0;
	for (ll i = 1; i <= (ll)n; i++) {
		if (visited[i] == 1)continue;
		if (arr[n - th] == i) {
			visited[i] = 1;
			return goo(th - 1, ans += cnt*fac[th]);
		}
		else {
			cnt += 1;
		}
	}
}
int main() {
	long long v = 1;
	for (long long i = 1; i <= 20; i++) {
		v *= i;
		fac[i] = v;
	}
	fac[0] = 1;
	scanf("%d %d", &n, &t);
	if (t == 1) {
		scanf("%lld", &c);
		go(n - 1, c);
		for (int i = 1; i <= n; i++) {
			if (i == 1) printf("%d", arr[i]);
			else printf(" %d", arr[i]);
		}
	}
	else {
		for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
		printf("%lld", goo(n - 1, 0));
	}
	return 0;
}