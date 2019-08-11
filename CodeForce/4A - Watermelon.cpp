#include <stdio.h>
int main() {
	int w;
	scanf("%d", &w);
	if (w >= 4 && w % 2 == 0) printf("YES");
	else printf("NO");
	return 0;
}