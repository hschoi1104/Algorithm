#include <stdio.h>
int arr[102];
int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	int index = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < q; i++) {
		int x;
		scanf("%d", &x);
		for (int i = 0; i < n; i++) {
			if (arr[i] > x) {
				printf("%d\n", i + 1);
				break;
			}
			x -= arr[i];
		}
	}
	return 0;
}