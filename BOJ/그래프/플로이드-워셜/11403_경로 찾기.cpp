#include <stdio.h>
#include <algorithm>
#define INF 10000000
using namespace std;

int map[110][110];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0)map[i][j] = INF;
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] > map[i][k] + map[k][j])
					map[i][j] = map[i][k] + map[k][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] != INF ) {
				if (j == 0) printf("1");
				else printf(" 1");
			}
			else {
				if (j == 0) printf("0");
				else printf(" 0");
			}
		}
		printf("\n");
	}
	return 0;
}
