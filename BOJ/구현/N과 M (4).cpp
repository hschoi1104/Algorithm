#include <stdio.h>
#include <vector>
using namespace std;
vector<int>ans;
int n, m;

void go(int here, int depth, int k) {
	if (depth == k) {
		for (int i = 0; i < m; i++)
			printf("%d ", ans[i]);
		printf("\n");
		return;
	}
	for (int i = here; i <= n; i++) {
		ans.push_back(i);
		go(i, depth + 1, k);
		ans.pop_back();
	}

	return;
}
int main() {
	scanf("%d %d", &n, &m);
	go(1, 0, m);
	return 0;
}