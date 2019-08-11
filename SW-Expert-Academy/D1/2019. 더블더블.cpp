#include <stdio.h>
int main() {
	int t, n = 1;
	scanf("%d", &t);
	printf("%d ", n);
	while (t--)	printf("%d ", n <<= 1);
	return 0;
}