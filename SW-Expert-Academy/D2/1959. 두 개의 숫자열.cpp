#include <stdio.h>
int arr[21], brr[21], tmp;
void swap(int n) {
	for (int i = 0; i < n; i++) {
		tmp = brr[i];
		brr[i] = arr[i];
		arr[i] = tmp;
	}
	return;
}
int main() {
	int t; scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		int n, m; scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
		for (int i = 0; i < m; i++) scanf("%d", &brr[i]);
		if (n > m) {
			swap(n);
			tmp = n;
			n = m;
			m = tmp;
		}
		int ans = -99999999;
		for (int i = 0; i < m-n+1; i++) {
			int tmp = 0;
			for (int j = 0; j < n; j++) {
				tmp += arr[j] * brr[j+i];
			}
			if (ans < tmp) ans = tmp;
		}
		printf("#%d %d\n", tt, ans);
	}
	return 0;
}