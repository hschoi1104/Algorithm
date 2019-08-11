#include <stdio.h>
int main() {
	int c, k,val=1;
	scanf("%d %d", &c, &k);
	while (k--) val *= 10;
	if (c%val >= val / 2) printf("%d",c - c % val + val);
	else printf("%d", c - c % val);
	return 0;
}