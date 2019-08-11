#include<stdio.h>
int main() {
	int n, m, k,t=0;
	scanf("%d %d %d", &n, &m, &k);
	if (n / 2 > m) t = m;
	else t = n / 2;
	if ((n + m - (t * 3)) >= k) {
		printf("%d", t);
		return 0;
	}
	else {
		t-=((k - (n + m - (t * 3))) / 3);
		if (((k - (n + m - (t * 3))) % 3) > 0) t -= 1;
	}
	if (t>=0) printf("%d", t);
	else printf("0");
	return 0;
}