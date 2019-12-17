#include <stdio.h>
int arr[51];
void qsort(int s, int e) {
	if (s >= e) return;
	int p = s;
	int i = p + 1;
	int j = e;
	int tmp;
	while (i <= j) {
		while (i <= e && arr[i] <= arr[p]) i++;
		while (j > s&& arr[j] >= arr[p])j--;
		if (i > j) {
			tmp = arr[j];
			arr[j] = arr[p];
			arr[p] = tmp;
		}
		else {
			tmp = arr[j];
			arr[j] = arr[i];
			arr[i] = tmp;
		}
	}
	qsort(s, j - 1);
	qsort(j + 1, e);
}
int main() {
	int t; scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
		qsort(0, n - 1);
		printf("#%d ", tt);
		for (int i = 0; i < n; i++) printf("%d ", arr[i]);
		printf("\n");
	}
	return 0;
}