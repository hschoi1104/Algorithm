#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
vector<vector<int>>g;
int b[1002];
int chk[1002];
int n, m, ans = 0;
//���� �� �� ���� ��Ī�� �Ǿ��ִٸ� ������ ����� ���� ���󰡼� ���� �ɷ� �о���
int dfs(int cur) {
	if (chk[cur] == 2) return 0;
	chk[cur] += 1;
	for (int i = 0; i < g[cur].size(); i++) {
		int next = g[cur][i];
		//�湮�Ǿ��ִٸ� ���� ���� �о���
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
	//�׷��� ����
	for (int i = 0; i < n; i++) {
		int c, x;
		scanf("%d", &c);
		for (int j = 0; j < c; j++) {
			scanf("%d", &x);
			g[i + 1].push_back(x);
		}
	}
	//��������� ��Ī
	for (int i = 1; i <= n; i++) {
		memset(chk, 0, sizeof(chk));
		if (dfs(i) == 1) ans += 1;
	}
	//k�� �� ������
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