#include <stdio.h>
int ans = 1, n;
char c;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %1c", &c);
		if (c == 'S') ans += 1;
		else {
			scanf(" %1c", &c);
			ans += 1;
			i++;
		}
	}
	if (ans >= n) printf("%d", n);
	else printf("%d", ans);
	return 0;
}