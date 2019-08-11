#include <stdio.h>
int main() {
	int t, c = 1, y, m, d, num;
	int chk[13] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	scanf("%d", &t);
	while (t--) {
		y = m = d = 1;
		scanf("%d", &num);
		y = num / 10000;
		num %= 10000;
		m = num / 100;
		num %= 100;
		d = num;
		if (d <= chk[m-1]) {
			printf("#%d ", c++);
			if (y < 10) printf("000%d/", y);
			else if (y < 100) printf("00%d/", y);
			else if (y < 1000) printf("0%d/", y);
			else printf("%d/", y);

			if (m < 10) printf("0%d/", m);
			else printf("%d/", m);

			if (d < 10) printf("0%d\n", d);
			else printf("%d\n", d);
			}
		else printf("#%d -1\n", c++);
	}
	return 0;
}