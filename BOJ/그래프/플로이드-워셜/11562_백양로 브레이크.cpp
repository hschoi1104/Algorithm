#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int arr[251][251];
int INF = 1e9;
int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) arr[i][j] = INF;

	for (int i = 0; i < m; i++) {
		int u, v, b;
		scanf("%d %d %d", &u, &v, &b);
		arr[u][v] = 0; arr[v][u] = 0;
		if (b == 0) {
			arr[v][u] = 1;
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][k] + arr[k][j] < arr[i][j]) arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		if (s == e) printf("0\n");
		else printf("%d\n", arr[s][e]);
	}
	return 0;
}