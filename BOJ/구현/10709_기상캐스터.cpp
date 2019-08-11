#include <stdio.h>
char map[101][101];
int arr[101][101];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf(" %1c", &map[i][j]);
	for (int i = 0; i < n; i++) {
		int flag = false;
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '.' && flag == false) arr[i][j] = -1;
			else if (map[i][j] == '.' && flag == true) arr[i][j] = arr[i][j - 1] + 1;
			else if (map[i][j] == 'c') {
				flag = true;
				arr[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)printf("%d ", arr[i][j]);
		printf("\n");
	}
}