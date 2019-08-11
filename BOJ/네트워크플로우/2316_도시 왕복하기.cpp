#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
vector<vector<int>>g;
int c[802][802];
int f[802][802];
int path[802];
int INF = 999999999;
int r, u, v, n, p, x, s = 401, t = 2, ans = 0;
int main() {
	scanf("%d %d", &n, &p);
	g.resize(802);
	//��������
	for (int i = 1; i <= n; i++) {
		g[i].push_back(i + 400);
		c[i][i + 400] += 1;
	}
	//�׷��� ����
	for (int i = 1; i <= p; i++) {
		scanf("%d %d", &u, &v);
		g[u + 400].push_back(v); g[v + 400].push_back(u);
		g[v].push_back(u+400); g[u].push_back(v+400);
		c[u + 400][v] += 1; c[v + 400][u] += 1;
	}
	//������ ī��
	//������θ� ��� ã��
	while (1) {
		path[s] = path[t] = -1;
		int chk[802] = { 0 };
		queue<int>q;
		q.push(s);
		chk[s] = 1;
		while (!q.empty()) {
			int cur = q.front();
			if (cur == t) break;
			q.pop();
			for (int i = 0; i < g[cur].size(); i++) {
				int next = g[cur][i];
				if (chk[next] == 0 && c[cur][next] - f[cur][next] > 0) {
					path[next] = cur;
					chk[next] = 1;
					q.push(next);
					if (next == t) break;
				}
			}
		}
		//���� ��θ� ã�� ���Ѵٸ� break;
		if (path[t] == -1) break;
		
		//���ܰ����� �ܷ����� ������ ������Ʈ
		int pos = t; int F = 1;
		while (path[pos] != -1) {
			int prev = path[pos];
			f[prev][pos] += F; f[pos][prev] -= F;
			pos = prev;
		}
		ans += F;
	}
	printf("%d", ans);
	return 0;
}