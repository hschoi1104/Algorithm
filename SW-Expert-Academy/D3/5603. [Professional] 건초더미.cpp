#include <iostream>
using namespace std;

void qsort(int *arr,int s, int e) {
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
	qsort(arr,s, j - 1);
	qsort(arr,j + 1, e);
}
int main() {
	int tt; cin >> tt;
	for (int t = 1; t <= tt; t++) {
		int n, sum = 0,ans=0; cin >> n;
		int* arr = (int*)malloc(sizeof(int) * n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		qsort(arr, 0, n - 1);
		sum /= n;


	}
	return 0;
}