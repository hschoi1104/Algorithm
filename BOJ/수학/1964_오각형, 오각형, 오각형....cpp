#include <stdio.h>
long long ans = 1, n;
int main() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)
		ans += (3 * (i - 1) + 4);
	printf("%lld\n", ans % 45678);
	return 0;
}