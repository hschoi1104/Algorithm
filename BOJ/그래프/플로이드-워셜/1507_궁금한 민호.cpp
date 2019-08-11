#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
int arr[30][30];
int posible[30][30];
int INF = 1e9;
int n;

bool chk() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != posible[i][j]) return false;
		}
	}
	return true;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	set<p>ans;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (i == j) continue;
			int temp = arr[i][j];
			bool flag = false;
			for (int k = 0; k < n; k++) {
				if (k == i || k == j) continue;
				if (arr[i][k] + arr[k][j] == arr[i][j]) {
					flag = true;
					break;
				}
			}
			if (flag == false)	ans.insert({ i,j });
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)continue;
			posible[i][j] = INF;
		}
	}
	int sum = 0;
	for (auto it = ans.begin(); it != ans.end(); it++) {
		sum += arr[it->first][it->second];
		posible[it->first][it->second] = posible[it->second][it->first] = arr[it->first][it->second];
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (posible[i][j] > posible[i][k] + posible[k][j]) posible[i][j] = posible[i][k] + posible[k][j];
			}
		}
	}

	if (chk() == false) printf("-1");
	else printf("%d", sum);
	return 0;
}