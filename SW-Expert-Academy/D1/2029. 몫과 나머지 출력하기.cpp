#include <stdio.h>
int main() {
	int t,c=1,a,b;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &a, &b);
		printf("#%d %d %d\n", c++, a / b, a % b);
	}
	return 0;
}