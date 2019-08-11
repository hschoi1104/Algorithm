#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>v;
int parent[200001];
int main() {
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		v.push_back(x);
	}
	fill(parent, parent + n, -2);
	int prev = 0, maxnode = 0;
	for (int i = 0; i < n; i++) {
		maxnode = max(maxnode, v[i]);
		if (i == 0) {
			parent[v[0]] = -1;
			prev = v[0];
			continue;
		}
		if (parent[v[i]] == -2) parent[v[i]] = prev;
		else if (parent[prev] == v[i]) {
			prev = v[i];
			continue;
		}
		prev = v[i];
	}
	printf("%d\n", maxnode + 1);
	for (int i = 0; i <= maxnode; i++) printf("%d ", parent[i]);
	return 0;
}