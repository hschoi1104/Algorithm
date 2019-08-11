#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	int t = 10, cnt = 1;
	while (t--) {
		int n, ans = 0;
		int arr[1001];
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
		for (int i = 1; i <= n; i++) {
			if (i == 1 && (arr[i] > arr[i + 1] || arr[i] > arr[i + 2])) {
				ans += arr[i] - max(arr[i + 1], arr[i + 2]);
				continue;
			}
			else if (i == 2 && ((arr[i] > arr[i + 1] || arr[i] > arr[i + 2]) || arr[i] > arr[i - 1])) {
				ans += arr[i] - max(max(arr[i - 1], arr[i + 1]), arr[i + 2]);
				continue;
			}
			else if (i == n - 1 && (arr[i] > arr[i - 1] || (arr[i] > arr[i + 1] || arr[i] > arr[i - 2]))) {
				ans += arr[i] - max(max(arr[i - 1], arr[i + 1]), arr[i - 2]);
				continue;
			}
			else if (i == n && (arr[i] > arr[i - 1] || arr[i] > arr[i - 2])) {
				ans += arr[i] - max(arr[i - 1], arr[i - 2]);
				continue;
			}
			else {
				int val = max(max(arr[i - 2], arr[i - 1]), max(arr[i + 1], arr[i + 2]));
				if (arr[i] > val) ans += arr[i] - val;
			}
		}
		printf("#%d %d\n", cnt++, ans);
	}
	return 0;
}