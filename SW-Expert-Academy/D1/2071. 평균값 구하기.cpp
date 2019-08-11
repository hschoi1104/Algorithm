#include <stdio.h>
#include <math.h>

int main() {
	int n, cnt = 1;
	scanf("%d", &n);
	while (n--) {
		double sum = 0.0, x;
		for (int i = 0; i < 10; i++) {
			scanf("%lf", &x);
			sum += x;
		}
		printf("#%d %.0lf\n", cnt++, round(sum / 10.0));
	}
	return 0;
}