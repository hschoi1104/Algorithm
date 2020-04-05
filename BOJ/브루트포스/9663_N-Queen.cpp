#include <stdio.h>

int n, col[15], dia[2][50], ans;
void go(int i) {
	if (i == n) ans += 1;
	else {
		for (int j = 0; j < n; j++) {
			if (!col[j] && !dia[0][i - j + 15] && !dia[1][i + j]) {
				col[j] = dia[0][i - j + 15] = dia[1][i + j] = 1;
				go(i + 1);
				col[j] = dia[0][i - j + 15] = dia[1][i + j] = 0;
			}
		}
	}
	return;
}
int main() {
	scanf("%d", &n);
	go(0);
	printf("%d", ans);
	return 0;
}