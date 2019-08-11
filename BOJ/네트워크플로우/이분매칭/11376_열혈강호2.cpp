#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
vector<vector<int>>g;
int b[1002];
int chk[1002];
int n, m, ans = 0;
//만약 그 한 점이 매칭이 되어있다면 그점에 연결된 점을 따라가서 다음 걸로 밀어줌
int dfs(int cur) {
	if (chk[cur] == 2) return 0;
	chk[cur] += 1;
	for (int i = 0; i < g[cur].size(); i++) {
		int next = g[cur][i];
		//방문되어있다면 이전 점을 밀어줌
		if (b[next] == 0 || dfs(b[next]) == 1) {
			b[next] = cur;
			return 1;
		}
	}
	return 0;
}
int main() {
	scanf("%d %d %d", &n, &m, &k);
	g.resize(n + 1);
	//그래프 생성
	for (int i = 0; i < n; i++) {
		int c, x;
		scanf("%d", &c);
		for (int j = 0; j < c; j++) {
			scanf("%d", &x);
			g[i + 1].push_back(x);
		}
	}
	//모든점에서 매칭
	for (int i = 1; i <= n; i++) {
		memset(chk, 0, sizeof(chk));
		if (dfs(i) == 1) ans += 1;
	}
	//k번 더 진행함
	for (int i = 1; i <= k; i++) {
		memset(chk, 0, sizeof(chk));
		if (dfs(i) == 1) {
			ans += 1;
			k -= 1;
		}
	}
	printf("%d", ans);
	return 0;
}