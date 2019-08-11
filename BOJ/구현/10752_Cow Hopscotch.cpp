#include<stdio.h>
using namespace std;
char arr[16][16];
int r, c;
int ans = 0;
void go(int y,int x,char ch) {
	if (ch != arr[r - 1][c - 1]) {
		ans += 1;
		if(y == r - 2 || x == c - 2) return;
	}

	for (int i = y + 1; i < r - 1; i++) {
		for (int j = x + 1; j < c - 1; j++) {
			if (arr[i][j] != ch) go(i, j, arr[i][j]);
		}
	}
}
int main() {
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf(" %1c", &arr[i][j]);
		}
	}
	go(0, 0, arr[0][0]);
	printf("%d", ans);
	return 0;
}