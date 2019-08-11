#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int cnt, x, ans = 0;
		int arr[101];
		memset(arr, 0, sizeof(arr));
		scanf("%d", &cnt);
		for (int i = 0; i < 1000; i++) {
			scanf("%d", &x);
			arr[x] += 1;
		}
		for (int i = 100; i >= 0; i--) ans = max(ans, arr[i]);
		for (int i = 100; i >= 0; i--) if (ans == arr[i]) {
			printf("#%d %d\n", cnt, i);
			break;
		}
	}
	return 0;
}