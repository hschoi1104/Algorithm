#include <stdio.h>
int main() {
	int t; scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		int n,ans=1; scanf("%d", &n);
		for (int i = 2; i <= n; i++) {
			if (i % 2 == 1) ans += i;
			else ans -= i;
		}
		printf("#%d %d\n", tt, ans);
	}
	return 0;
}