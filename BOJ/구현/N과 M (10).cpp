#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
vector<int>ans;
vector<int>arr;
set<int>ma;
int chk[10];
int n, m;

void go(int here, int depth, int k) {
	if (depth == k) {
		int num = ans[0];
		for (int i = 1; i < m; i++) {
			num *= 10;
			num += ans[i];
		}
		if (ma.find(num) == ma.end()) {
			ma.insert(num);
			for (int i = 0; i < m; i++) {
				printf("%d ", ans[i]);
			}
			printf("\n");
		}
		return;
	}
	for (int i = here; i < n; i++) {
		if (chk[i] == 0) {
			ans.push_back(arr[i]);
			chk[i] = 1;
			go(i + 1, depth + 1, k);
			ans.pop_back();
			chk[i] = 0;
		}
	}
	return;
}
int main() {
	int x;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());
	go(0, 0, m);
	return 0;
}