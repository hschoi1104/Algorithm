#include <stdio.h>
#include <algorithm>
#define INF 100000000
using namespace std;

int map[102][102];
int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) map[i][j] = 0;
			else map[i][j] = INF;
		}
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b; 
		scanf("%d %d", &a, &b);
		map[a][b] = 1;
		map[b][a] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] > map[i][k] + map[k][j])
					map[i][j] = map[i][k] + map[k][j];
			}
		}
	}
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
			if (map[1][i] !=INF)cnt++;
	}
	printf("%d", cnt);
	return 0;
}
