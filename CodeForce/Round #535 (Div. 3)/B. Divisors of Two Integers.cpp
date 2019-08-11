#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int arr[1000];
int chk[100000];
int visited[100000];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		visited[arr[i]] += 1;
	}
	sort(arr, arr + n);
	for (int i = 1; i <= arr[n - 1]; i++) {
		if (arr[n - 1] % i == 0) chk[i] = 1;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (chk[arr[i]] == 1 && visited[arr[i]] == 2)ans = max(ans, arr[i]);
		if (chk[arr[i]] != 1)ans = max(ans, arr[i]);
	}
	printf("%d %d", arr[n - 1], ans);
	return 0;
}