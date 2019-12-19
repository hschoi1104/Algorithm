#include <stdio.h>
int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int main() {
	int t; scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);
		int ans = 0;
		if (a == c) {
			ans = d - b + 1;
		}
		else {
			ans = arr[a] - b + d + 1;
			if (c - a >= 2) for (int i = a + 1; i <= c - 1; i++) ans += arr[i];
		}
		printf("#%d %d\n", tt, ans);
	}
	return 0;
}