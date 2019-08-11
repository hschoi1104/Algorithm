#include <stdio.h>
using namespace std;
char arr[110][110];
int r, c, a, b;
int main() {
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) for (int j = 0; j < c; j++)	scanf(" %c", &arr[i][j]);
	for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) {
		arr[2 * r - i - 1][j] = arr[2 * r - i - 1][2 * c - j - 1] = arr[i][2 * c - j - 1] = arr[i][j];
	}
	scanf("%d %d", &a, &b);
	if (arr[a-1][b-1] == '.') arr[a-1][b-1] = '#';
	else arr[a-1][b-1] = '.';
	for (int i = 0; i < 2 * r; i++) {
		for (int j = 0; j < 2 * c; j++)printf("%c", arr[i][j]);
		printf("\n");
	}
}