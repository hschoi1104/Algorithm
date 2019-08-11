#include <iostream>
#include <algorithm>
using namespace std;
char arr[121][121];
char s[51];
int dir = 0;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
//아래0 오른쪽 1 위2 왼쪽 3
int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", &s);
	int x = 60, y = 60;
	for (int i = 0; i < 120; i++) {
		for (int j = 0; j < 120; j++) {
			arr[i][j] = '-';
		}
	}
	arr[y][x] = '.';
	for (int i = 0; i < n; i++) {
		if (s[i] == 'R')dir -= 1;
		else if (s[i] == 'L') dir += 1;
		if (dir < 0)dir = 3;
		if (dir > 3)dir = 0;
		if (s[i] == 'F') {
			x += dx[dir];
			y += dy[dir];
			arr[y][x] = '.';
		}
	}
	int sx = 120, sy = 120, ex = 0, ey = 0;
	for (int i = 0; i < 120; i++) {
		for (int j = 0; j < 120; j++) {
			if (arr[i][j] == '.') {
				sx = min(sx, j);
				sy = min(sy, i);
				ex = max(ex, j);
				ey = max(sy, i);
			}
		}
	}
	for (int i = sy; i <= ey; i++) {
		for (int j = sx; j <= ex; j++) {
			if (arr[i][j] == '.')printf(".");
			else printf("#");
		}
		printf("\n");
	}

}