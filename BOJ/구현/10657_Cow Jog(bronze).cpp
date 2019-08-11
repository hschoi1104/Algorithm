#include <stdio.h>
#include <algorithm>
#include <utility>
#include <limits.h>
using namespace std;
typedef pair<int, int>p;
p arr[100001];
int ans = 1;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}
	int minspeed = arr[n - 1].second;
	for (int i = n - 2; i >= 0; i--) {
		if (arr[i].second > arr[i + 1].second) continue;
		else if (arr[i].second <= minspeed) {
			ans += 1;
			minspeed = arr[i].second;
		}
	}
	printf("%d", ans);
	return 0;
}