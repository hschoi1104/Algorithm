#include <stdio.h>
int coin[8] = { 50000,10000,5000,1000,500,100,50,10 };
int main() {
	int t; scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		int val; scanf("%d", &val);
		printf("#%d\n", tt);
		for (int i = 0; i < 8; i++) {
			printf("%d ", val / coin[i]);
			val -= (val / coin[i]) * coin[i];
		}
		printf("\n");
	}
	return 0;
}