#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>>v;
int parent[60];
int ans = 0, root = 0;
void search(int k, int m) {
	bool find = false;
	for (int i = 0; i < v[k].size(); i++) {
		int next = v[k][i];
		if (next == m) continue;
		find = true;
		search(next, m);
	}
	if (!find) ans += 1;
	return;
}
int main() {
	int n, x, m;
	v.resize(60);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x == -1) {
			root = i;
			continue;
		}
		parent[x] = i;
		v[x].push_back(i);
	}

	scanf("%d", &m);
	search(root, m);

	if (m == root) printf("0");
	else printf("%d", ans);
	return 0;
}