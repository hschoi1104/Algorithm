#include <stdio.h>
#include <algorithm>
#define INF 10000000
using namespace std;

int map[102][102];
int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)map[i][j] = 0;
			else map[i][j] = INF;
		}
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b, c; 
		scanf("%d %d %d", &a, &b, &c);
		map[a][b] = min(map[a][b],c);
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] > map[i][k] + map[k][j])
					map[i][j] = map[i][k] + map[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j == 1) {
				if (map[i][j] == INF) printf("0");
				else printf("%d", map[i][j]);
			}
			else {
				if (map[i][j] == INF) printf(" 0");
				else printf(" %d", map[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}
