#include <stdio.h>
#include <algorithm>
#define INF 1000000001
using namespace std;

int arr[12];
int ma = -INF;
int mi = INF;
int n;

void go(int start, int sum, int a, int b, int c, int d) {
	if (start == n) {
		mi = min(mi, sum);
		ma = max(ma, sum);
		return;
	}
	if (a == 0 && b == 0 && c == 0 && d == 0) {
		mi = min(mi, sum);
		ma = max(ma, sum);
		return;
	}
	if (a > 0) go(start + 1, sum + arr[start], a-1, b, c, d);
	if (b > 0)go(start + 1, sum - arr[start], a, b-1, c, d);
	if (c > 0)go(start + 1, sum*arr[start], a, b, c-1, d);
	if (d > 0) go(start + 1, sum / arr[start], a, b, c, d-1);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	go(1, arr[0], a, b, c, d);
	printf("%d\n%d\n", ma, mi);
	return 0;
}