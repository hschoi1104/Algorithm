#include <stdio.h>
double arr[10] = { 4,8,2,3,9,7,1,6,10,5 };
void qsort(int s, int e) {
	if (s >= e) return;
	int pivot = s;
	int i = pivot + 1;
	int j = e;
	double tmp;
	while (i <= j) {
		while (i <= e && arr[i] <= arr[pivot]) i++;
		while (j > s&& arr[j] >= arr[pivot]) j--;
		if (i > j) {
			tmp = arr[j];
			arr[j] = arr[pivot];
			arr[pivot] = tmp;
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
		for (int i = 0; i < 10; i++) scanf("%lf", &arr[i]);
		qsort(0, 9);
		double sum = 0.0;
		for (int i = 1; i < 9; i++) sum += arr[i];
		printf("#%d %0.f\n", tt, (sum / 8.0));
	}
	return 0;
}