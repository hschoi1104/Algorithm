#include <stdio.h>
#include <algorithm>
#include <limits.h>
using namespace std;
int arr[300001];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) scanf("%d", &arr[i]);
	int left = 0, right = 1000000000, ans = INT_MAX;
	while (left + 1 < right) {
		int mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			cnt += arr[i] / mid;
			if (arr[i] % mid != 0)cnt += 1;
		}
		if (cnt <= n) {
			right = mid;
			ans = min(ans, mid);
		}
		else {
			left = mid;
		}
	}
	printf("%d", ans);
	return 0;
}