#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		double p = 0;
		while (n--) {
			p += 0.5;
			p *= 2.0;
		}
		printf("%d\n", (int)p);
	}
	return 0;
}