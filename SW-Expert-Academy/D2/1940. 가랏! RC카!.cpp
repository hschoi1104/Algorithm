#include <stdio.h>
int arr[12];
int main() {
	int t; scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		int n; scanf("%d", &n);
		int speed = 0;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int a, b; scanf("%d", &a);
			if (a != 0) scanf("%d", &b);
			if (a == 1) speed += b;
			if (a == 2) speed -= b;
			if (speed < 0) speed = 0;
			ans += speed;
		}
		printf("#%d %d\n", tt, ans);
	}
	return 0;
}