#include <stdio.h>
#include <vector>
#include <algorithm>
#define INF 10000000
using namespace std;
vector<int>ans;
int map[102][102];
int path[102][102];
void go(int s, int e) {
	if (path[s][e] != 0) {
		go(s, path[s][e]);
		ans.push_back(path[s][e]);
		go(path[s][e], e);
	}
}
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
		map[a][b] = min(map[a][b], c);
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] > map[i][k] + map[k][j]){
					map[i][j] = map[i][k] + map[k][j];
					path[i][j] = k;
				}
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
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || map[i][j] == INF)printf("0");
			else {
				go(i, j);
				printf("%d ", ans.size() + 2);
				printf("%d ", i);
				for (int u = 0; u < ans.size(); u++) printf("%d ", ans[u]);
				printf("%d", j);
				ans.clear();
			}
			printf("\n");
		}
	}
	return 0;
}
