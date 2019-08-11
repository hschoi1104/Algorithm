#include <stdio.h>
bool arr[10000002];
using namespace std;
typedef long long ll;
int cnt = 0;
int main() {
	ll n, m;
	scanf("%lld %lld", &n, &m);
	for (int i = 2; i <= 10000001; i++) {
		if (arr[i] == true)continue;
		for (int j = i * 2; j <= 10000000; j += i) {
			arr[j] = true;
		}
	}
	for (int i = 2; i <= 10000000; i++) {
		if (arr[i] == true) continue;
		for (ll j = i; j <= m; j *= i) {
			if (i > m / j) break;
			if (n<=i*j && i*j<=m) cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}