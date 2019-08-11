#include <stdio.h>
#include <vector>
using namespace std;
vector<int>ans;
int chk[10];
int n, m;

void go(int here, int depth, int k) {
	if (depth == k) {
		for (int i = 0; i < m; i++)
			printf("%d ", ans[i]);
		printf("\n");
		return;
	}
	for (int i = here; i <= n; i++) {
		if (chk[i] == 0) {
			chk[i] = 1;
			ans.push_back(i);
			go(i + 1, depth + 1, k);
			chk[i] = 0;
			ans.pop_back();
		}
	}
	return;
}
int main() {
	scanf("%d %d", &n, &m);
	go(1, 0, m);
	return 0;
}