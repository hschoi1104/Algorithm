#include <stdio.h>
using namespace std;
int arr[11][11];
int go(int a, int b) {
	if (b > a) return 0;
	int& ret = arr[a][b];
	if (ret != 0) return ret;
	if (b == 0) ret = go(a - 1, b);
	else return ret = go(a - 1, b - 1) + go(a - 1, b);
}
int main() {
	arr[0][0] = 1;
	int n; scanf("%d", &n);
	for (int tt = 1; tt <= n; tt++) {
		int a; scanf("%d", &a);
		printf("#%d\n", tt);
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < a && j <= i; j++) {
				printf("%d ", go(i, j));
			}
			printf("\n");
		}
	}
	return 0;
}