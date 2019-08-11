#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[201];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	printf("%d\n", arr[n / 2]);
	return 0;
}