#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[100001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	int size = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (size > arr[i])break;
		size++;
	}
	printf("%d", size);
	return 0;
}