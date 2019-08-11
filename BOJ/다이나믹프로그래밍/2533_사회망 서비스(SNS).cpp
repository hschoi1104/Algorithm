#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>>v;
vector<vector<int>>t;
int dp[1000001][2];//�ε����ѳ������
//�󸮾���Ͷ�� �ڽ��� �ΰ��� ������ �ü� ������
//�ƴ϶�� �ڽ��� ������ �󸮾���Ͱ� �;��Ѵ�.
int visited[1000001];
void make_tree(int cur) {
	visited[cur] = 1;
	for (int i = 0; i < v[cur].size(); i++) {
		if (visited[v[cur][i]] != 1) {
			t[cur].push_back(v[cur][i]);
			visited[cur] = 1;
			make_tree(v[cur][i]);
		}
	}
	return;
}
int go(int cur,int type) {//�θ��� type 0 �Ϲݳ�� 1 �󸮾����
	int &res = dp[cur][type];
	if (res != -1) return res;

	if (type == 0) {//�θ� �Ϲݳ�忴�ٸ� ������� ������ �󸮾���� ���
		res = 0;
		for (int i = 0; i < t[cur].size(); i++) {
			int next = t[cur][i];
			res += go(next, 1);
		}
	}
	else if(type ==1) {//�θ� �󸮾���Ϳ��ٸ� �ΰ��� ��� ������
		res = 1;
		for (int i = 0; i < t[cur].size(); i++) {
			int next = t[cur][i];
			res += min(go(next, 1),go(next,0));
		}
	}
	return res;
}
int main() {
	int n;
	scanf("%d", &n);
	//init
	v.resize(n + 1);
	t.resize(n + 1);
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			dp[i][j] = -1;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	//�����׷����� Ʈ���� �������
	make_tree(1);

	printf("%d\n", min(go(1, 0), go(1, 1)));
	return 0;
}