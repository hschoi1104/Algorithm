#include <stdio.h>
#include <limits.h>
#include <algorithm>
using namespace std;
int arr[100001];
int ans = INT_MAX;
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int left = 0, right = 1000000;
	while (left+1 < right) {
		int mid = (left + right) / 2; // k
		int cnt = 0;
		int account = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] > mid) {
				cnt = INT_MAX;
				break;
			}
			if (arr[i] <= account) {
				account -= arr[i];
			}
			else if (arr[i] > account) {
				cnt += 1;
				account = mid - arr[i];
			}
		}

		if (cnt <= m) {
			right = mid;
			if (cnt != INT_MAX)
				ans = min(ans, mid);
		}
		else if (cnt > m) {
			left = mid;
		}
	}
	printf("%d\n", ans);
	return 0;
}