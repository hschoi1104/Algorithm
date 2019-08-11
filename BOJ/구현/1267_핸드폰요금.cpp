#include <stdio.h>
int main() {
	int t;
	scanf("%d", &t);
	int y = 0;
	int m = 0;
	while (t--) {
		int time = 0;
		scanf("%d", &time);
		y += ((time / 30) + 1) * 10;
		m += ((time / 60) + 1) * 15;
	}
	if (y < m) printf("Y %d", y);
	else if(y>m) printf("M %d", m);
	else printf("Y M %d", y);
	return 0;
}