#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		bool flag = false;
		int t = i;
		while (t > 0) {
			if (t % 10 % 3 == 0 && t % 10 != 0) {
				printf("-");
				flag = true;
			}
			t /= 10;
		}

		if (flag == false) printf("%d ", i);
		else printf(" ");
	}
	return 0;
}