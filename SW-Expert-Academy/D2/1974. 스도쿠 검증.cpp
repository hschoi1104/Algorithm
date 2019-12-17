#include <stdio.h>
int arr[9][9],chk[10];

void init() {for (int i = 0; i <= 9; i++) chk[i] = 0;}
bool check(int mode, int i, int j) {
	init();
	bool flag = 1;
	if (mode == 0) for (int k = 0; k < 9; k++) {
		if (chk[arr[i][k]]) flag = false;
		chk[arr[i][k]] = 1;
	}
	else if (mode == 1) for (int k = 0; k < 9; k++) {
		if (chk[arr[k][j]]) flag = false;
		chk[arr[k][j]] = 1;
	}
	else {
		for (int k = i; k < i + 3; k++) {
			for (int l = j; l < j + 3; l++) {
				if (chk[arr[k][l]]) flag = false;
				chk[arr[k][l]] = 1;
			}
		}
	}
	return flag;
}
int main() {
	int t; scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++) scanf("%d", &arr[i][j]);
		bool ans = true;
		for (int i = 0; i < 9; i++) {
			if (ans == false) break;
			for (int j = 0; j < 9; j++) {
				if (i == j && i % 3 == 0 && !check(2, i, j)) ans = false;
				if (j == 0 && !check(0, i, j)) ans = false;
				if (i == 0 && !check(1, i, j)) ans = false;
				if (ans == false) break;
			}
		}
		printf("#%d %d\n", tt, ans ? 1 : 0);
	}
	return 0;
}