#include <stdio.h>
#include <vector>
#include <math.h>
#include <string.h>
using namespace std;
struct p {
	double x;
	double y;
};
vector<vector<int>>g;
vector<p> mouse;
vector<p> cave;
int chk[101];
int b[101];
int dfs(int cur) {
	if (chk[cur]) return 0;
	chk[cur] = 1;
	for (int i = 0; i < g[cur].size(); i++) {
		int next = g[cur][i];
		if (!b[next] || dfs(b[next])) {
			b[next] = cur;
			return 1;
		}
	}
	return 0;
}
double getdist(p a, p b) {
	return sqrt((b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y));
}
int main() {
	int n, m, s, v, ans = 0;
	double x, y;
	scanf("%d %d %d %d", &n, &m, &s, &v);
	g.resize(102);
	//mouse
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf", &x, &y);
		mouse.push_back({ y,x });
	}
	//cave
	for (int i = 0; i < m; i++) {
		scanf("%lf %lf", &x, &y);
		cave.push_back({ y,x });
	}
	for (int i = 0; i < mouse.size(); i++) {
		for (int j = 0; j < cave.size(); j++) {
			double dist = getdist(mouse[i], cave[j]);
			if (dist > (double)(s*v)) continue;
			g[i + 1].push_back(j + 1);
		}
	}
	//matching

	for (int i = 1; i <= 100; i++) {
		memset(chk, 0, sizeof(chk));
		if (dfs(i)) ans += 1;
	}
	printf("%d", n - ans);
	return 0;
}