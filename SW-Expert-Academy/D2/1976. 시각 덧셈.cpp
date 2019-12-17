#include <stdio.h>
int main() {
	int t; scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);
		int bd = b + d;
		int ac = a + c;
		if (bd >= 60) { ac += 1; bd -= 60; }
		if (ac > 12) ac -= 12;
		printf("#%d %d %d\n",tt, ac, bd);
	}
	return 0;
}