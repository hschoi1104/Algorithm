#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>ans;
vector<int>arr;
int n, m;

void go(int here, int depth, int k) {
	if (depth == k) {
		for (int i = 0; i < m; i++)
			printf("%d ", ans[i]);
		printf("\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		ans.push_back(arr[i]);
		go(i, depth + 1, k);
		ans.pop_back();
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