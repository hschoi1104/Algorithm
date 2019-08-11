#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", n--);
	while (n >= 0) {
		printf(" %d", n--);
	}
	return 0;
}