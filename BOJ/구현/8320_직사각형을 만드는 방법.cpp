#include <stdio.h>
int main() {
	int n,ans=0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int res = (n / i) - (i - 1);
		if (res > 0) ans += res;
	}
	printf("%d", ans);
	return 0;
}