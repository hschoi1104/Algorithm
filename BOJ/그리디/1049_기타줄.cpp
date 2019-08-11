#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
	int n, m, a, b, r6 = 1001, r1 = 1001, ans = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		r6 = min(r6, min(a, 6 * b));
		r1 = min(r1, b);
	}
	if (n / 6 > 0) {
		if (r6 < r1 * 6) ans += r6 * (n / 6);
		else ans += r1 * 6 * (n / 6);
	}
	if (n % 6 != 0) ans += min(r6, r1 * (n % 6));
	printf("%d", ans);
	return 0;
}
