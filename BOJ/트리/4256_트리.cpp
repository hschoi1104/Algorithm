#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>pre;
vector<int>in;
int pos = 0;
void dfs(int left, int right) {
	if (left > right) return;
	int mid = find(in.begin(), in.end(), pre[pos++])-in.begin();
	dfs(left, mid - 1);
	dfs(mid + 1, right);
	printf("%d ", in[mid]);
	return;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n,x;
		pre.clear();
		in.clear();
		pos = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			pre.push_back(x);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			in.push_back(x);
		}
		dfs(0,n-1);
		printf("\n");
	}
	return 0;
}