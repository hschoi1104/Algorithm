#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int arr[51][51];
int INF = 1e9;
int main() {
	int n, a, b;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == j) continue;
			arr[i][j] = INF;
		}
	}
	while (1) {
		scanf("%d %d", &a, &b);
		if (a == -1 && b == -1) break;
		arr[a][b] = arr[b][a] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j]) arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
	int ans = INF;
	for (int i = 1; i <= n; i++) {
		int res = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j || arr[i][j] == INF) continue;
			res = max(res, arr[i][j]);
		}
		ans = min(ans,res);
	}
	vector<int>aans;
	for (int i = 1; i <= n; i++) {
		int res = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j || arr[i][j] == INF) continue;
			res = max(res, arr[i][j]);
		}
		if (res == ans) aans.push_back(i);
	}
	printf("%d %d\n", ans, aans.size());
	sort(aans.begin(), aans.end());
	for (int i = 0; i < aans.size(); i++) {
		printf("%d ", aans[i]);
	}
	return 0;
}