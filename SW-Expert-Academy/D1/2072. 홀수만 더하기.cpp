#include <stdio.h>
int main() {
	int n,cnt=1;
	scanf("%d", &n);
	while (n--) {
		int sum = 0,x;
		for (int i = 0; i < 10; i++) {
			scanf("%d", &x);
			if(x%2==1) sum += x;
		}
		printf("#%d %d\n",cnt++,sum);
	}
	return 0;
}