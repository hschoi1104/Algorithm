#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector<vector<int>>g;
vector<vector<int>>sv;
int cnt = 0;
int scc[10001];
int num[10001];
stack <int> s;
int dfs(int cur) {
	int ret = num[cur] = ++cnt;
	s.push(cur);
	for (int next:g[cur]) {
		if (!num[next]) ret = min(ret, dfs(next));
		else if (!scc[next]) ret = min(ret, num[next]);
	}
	if (ret == num[cur]) {
		sv.push_back(vector<int>());
		while (1) {
			sv.back().push_back(s.top());
			scc[s.top()] = true;
			if (s.top() == cur) break;
			s.pop();
		}
		s.pop();
	}
	return ret;
}
int main() {
	int v, e, a, b;
	scanf("%d %d", &v, &e);
	g.resize(v + 1);
	for (int i = 0; i < e; i++) {
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
	}
	for (int i = 0; i < v; i++) if (!scc[i + 1]) dfs(i + 1);
	for (int i = 0; i < sv.size(); i++) sort(sv[i].begin(), sv[i].end());
	sort(sv.begin(), sv.end());
	printf("%d\n", sv.size());
	for (int i = 0; i < sv.size(); i++) {
		for (int j = 0; j < sv[i].size(); j++) 
			printf("%d ", sv[i][j]);
		printf("-1\n");
	}
	return 0;
}