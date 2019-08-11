#include <stdio.h>
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int sum = n;
	while (k--) {
		n *= 10;
		sum += n;
	}
	printf("%d\n", sum);
}