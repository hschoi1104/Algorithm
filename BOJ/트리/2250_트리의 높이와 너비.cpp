#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
vector<vector<int>>v;
int INF = 999999999;
int indegree[10001];
int order[10001];
int level[10001];
int ans[10001];
int t = 1;
p res[10001];
void travel(int cur, int l) {
	int left = v[cur][0];
	int right = v[cur][1];
	if (left != -1) {
		travel(left, l + 1);
	}
	order[cur] = t++;
	level[cur] = l;
	if (right != -1) {
		travel(right, l + 1);
	}
	return;
}
int main() {
	int n, a, b, c, root = 0;
	scanf("%d", &n);
	v.resize(n + 1);
	//input
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(b); v[a].push_back(c);
		indegree[b] += 1; indegree[c] += 1;
	}
	//find root
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			root = i;
			break;
		}
	}
	//travle
	travel(root, 1);

	//chk level-width
	int maxwidth = 0;
	int ans = INF;
	for (int i = 0; i <= n; i++) res[i] = { INF,0 };
	for (int i = 1; i <= n; i++) {
		res[level[i]].first = min(res[level[i]].first, order[i]);
		res[level[i]].second = max(res[level[i]].second, order[i]);
		if (res[level[i]].first != INF)maxwidth = max(maxwidth, res[level[i]].second - res[level[i]].first + 1);
	}

	//find ans
	for (int i = 1; i <= n; i++) {
		if (res[i].first != INF && maxwidth == res[i].second - res[i].first + 1)ans = min(ans, i);
	}
	printf("%d %d", ans, maxwidth);
	return 0;
}