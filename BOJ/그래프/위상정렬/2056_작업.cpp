#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>>v;
queue<int>q;
int in[10002];
int time[10002];
int finish[10002];

void bfs() {
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			in[next] -= 1;
			finish[next] = max(finish[next], time[next] + finish[cur]);
			if (in[next] == 0)q.push(next);
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	v.resize(n + 1);
	for(int i=1;i<=n;i++){
		scanf("%d", &time[i]);
		int x;
		scanf("%d", &x);
		for (int j = 0; j < x; j++) {
			int x;
			scanf("%d", &x);
			v[x].push_back(i);
			in[i]+=1;
		}
	}
	for (int i =1; i <= n; i++) {
		if (in[i] == 0) {
			q.push(i);
			finish[i] = time[i];
		}
	}
	bfs();
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, finish[i]);
	}
	printf("%d", ans);
	return 0;
}