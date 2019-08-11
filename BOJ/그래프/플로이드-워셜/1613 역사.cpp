#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[410][410];
int main() {
	int n, m, t;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][k] && arr[k][j]) arr[i][j] = 1;
			}
		}
	}

	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (!arr[a][b] && !arr[b][a]) printf("0\n");
		else if (arr[a][b] > arr[b][a]) printf("-1\n");
		else if (arr[a][b] < arr[b][a]) printf("1\n");
	}
}