#include <stdio.h>
int arr[11][11];
void snail(int n) {
	int cnt = n;
	int val = 1;
	int y = 0, x = 0;
	int sy = 0, sx = 0;
	while (1) {
		for (int i = x; i < sx + cnt; i++) {
			arr[y][i] = val++;
			x = i;
		}
		if (val == n * n + 1) return;
		y += 1;
		sy = y; sx = x;
		cnt--;
		for (int i = y; i < sy + cnt; i++) {
			arr[i][x] = val++;
			y = i;
		}
		if (val == n * n + 1) return;
		x -= 1;
		sy = y; sx = x;
		for (int i = x; i > sx - cnt; i--) {
			arr[y][i] = val++;
			x = i;
		}
		if (val == n * n + 1) return;
		y -= 1;
		cnt--;
		sy = y; sx = x;
		for (int i = y; i > sy - cnt; i--) {
			arr[i][x] = val++;
			y = i;
		}
		x += 1;
		sy = y; sx = x;
		if (val == n * n + 1) return;
	}
}
void print(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
int main() {
	int t; scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		int n; scanf("%d", &n);
		printf("#%d\n", tt);
		snail(n);
		print(n);
	}
	return 0;
}