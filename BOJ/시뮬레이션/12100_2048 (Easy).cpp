#include <iostream>
#include <algorithm>
#include<string.h>
using namespace std;
int arr[6][21][21], n, ans = 0;
void getMax(int cnt) {
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) ans = max(ans, arr[cnt][i][j]);
	return;
}
void move(int cnt, int dir) {
	for (int i = 0; i < n; i++) memset(arr[cnt][i], 0, sizeof(arr[cnt][i]));

	if (dir == 1 || dir == 3) {
		for (int i = 0; i < n; i++) {
			int num = 0, tmp = 0;
			if (dir == 1) {
				for (int j = n - 1; j >= 0; j--) {
					if (arr[cnt - 1][i][j] == 0) continue;
					else {
						if (tmp != 0 && tmp == arr[cnt - 1][i][j]) {
							num--;
							arr[cnt][i][n - 1 - num++] = tmp * 2;
							tmp = 0;
						}
						else if (arr[cnt - 1][i][j] != 0) {
							arr[cnt][i][n - 1 - num++] = arr[cnt - 1][i][j];
							tmp = arr[cnt - 1][i][j];
						}
					}
				}
			}
			if (dir == 3) {
				for (int j = 0; j < n; j++) {
					if (arr[cnt - 1][i][j]== 0) continue;
					else {
						if (tmp!=0 && tmp == arr[cnt - 1][i][j]) {
							num--;
							arr[cnt][i][num++] = tmp * 2;
							tmp = 0;
						}
						else if (arr[cnt - 1][i][j] != 0) {
							arr[cnt][i][num++] = arr[cnt - 1][i][j];
							tmp = arr[cnt - 1][i][j];
						}
					}
				}
			}
		}
	}
	else if (dir == 2 || dir == 4) {
		for (int j = 0; j < n; j++) {
			int tmp = 0, num = 0;
			if (dir == 2) {
				for (int i = n - 1; i >= 0; i--) {
					if (arr[cnt - 1][i][j] == 0) continue;
					else {
						if (tmp !=0 &&  tmp == arr[cnt-1][i][j]) {
							num--;
							arr[cnt][n-1-num++][j] = tmp * 2;
							tmp = 0;
						}
						else if (arr[cnt - 1][i][j] != 0) {
							arr[cnt][n - 1 - num++][j] = arr[cnt - 1][i][j];
							tmp = arr[cnt - 1][i][j];
						}
					}
				}
			}
			else if (dir == 4) {
				for (int i = 0; i < n; i++) {
					if (arr[cnt-1][i][j] == 0) continue;
					else {
						if (tmp !=0 && tmp == arr[cnt-1][i][j]) {
							num--;
							arr[cnt][num++][j] = tmp * 2;
							tmp = 0;
						}
						else if (arr[cnt - 1][i][j] != 0) {
							arr[cnt][num++][j] = arr[cnt - 1][i][j];
							tmp = arr[cnt - 1][i][j];
						}
					}
				}
			}
		}
	}
}
void go(int cnt) {
	getMax(cnt-1);
	if (cnt == 6) return;
	for (int k = 0; k < 4; k++) {
		move(cnt, k+1);
		go(cnt + 1);
	}
	return;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> arr[0][i][j];
	go(1);
	cout << ans;
	return 0;
}