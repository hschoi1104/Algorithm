#include <stdio.h>
#include <algorithm>
#define INF 100000000
using namespace std;

int map[102][102];
int main() {
	int n, m;
	scanf("%d %d", &n,&m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		map[a][b] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][k] && map[k][j]) map[i][j] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			else if(!map[i][j] && !map[j][i])cnt += 1;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
