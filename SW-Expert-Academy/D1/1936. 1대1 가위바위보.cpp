#include <stdio.h>
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	if (a < b) {
		if (b - a == 1) printf("B");
		else printf("A");
	}
	else {
		if (a-b == 1) printf("A");
		else printf("B");
	}
	return 0;
}