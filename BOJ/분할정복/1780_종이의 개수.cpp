#include <stdio.h>
using namespace std;
int arr[2188][2188];
int ans[3];//-1,0,1
bool chk(int n, int y, int x) {
	bool flag = false;
	for (int i = y; i < y + n; i++) {
		if (flag) break;
		for (int j = x; j < n + x; j++) {
			if (arr[y][x] != arr[i][j]) {
				flag = true;
				break;
			}
		}
	}
	if (!flag)return true;
	else return false;
}
void go(int n, int y, int x) {
	if (chk(n, y, x) == true) {
		ans[arr[y][x] + 1] += 1;
		return;
	}
	else{
	for (int i = y; i < y+n; i += n / 3)
		for (int j = x; j < x+n; j += n / 3)
			go(n / 3, i, j);
	}
	return;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)	for (int j = 0; j < n; j++)	scanf("%d", &arr[i][j]);
	go(n, 0, 0);
	printf("%d\n%d\n%d\n", ans[0], ans[1], ans[2]);
	return 0;
}