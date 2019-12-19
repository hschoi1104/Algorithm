#include <stdio.h>
int main() {
	int t; scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		int n; scanf("%d", &n);
		int cnt = 1;
		printf("#%d\n", tt);
		for (int i = 0; i < n; i++) {
			char ch; int c; scanf(" %c %d", &ch, &c);
			for (int i = 0; i < c; i++) {
				if (cnt == 11) {
					cnt = 1; printf("\n");
				}
				printf("%c", ch);
				cnt++;
			}
		}
		printf("\n");
	}
	return 0;
}