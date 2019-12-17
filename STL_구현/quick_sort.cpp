#include <stdio.h>
int arr[10] = { 4,8,2,3,9,7,1,6,10,5 };
void qsort(int s, int e) {
	if (s >= e) return;
	int pivot = s;
	int i = pivot + 1;
	int j = e;
	int tmp;
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
	qsort(0, 9);
	for (int i = 0; i < 10; i++) printf("%d ", arr[i]);
	return 0;
}