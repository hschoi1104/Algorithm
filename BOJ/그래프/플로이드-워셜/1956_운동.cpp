#include <stdio.h>
#include <algorithm>
#define INF 100000000
using namespace std;
int arr[402][402];
int main() {
	int v, e;
	scanf("%d %d", &v, &e);
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			arr[i][j] = INF;
		}
	}
	for (int i = 0; i < e; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		arr[a][b] = c;
	}
	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
	int ans = INF;
	for (int i = 1; i <= v; i++) {
		ans = min(ans, arr[i][i]);
	}
	if (ans == INF) printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}