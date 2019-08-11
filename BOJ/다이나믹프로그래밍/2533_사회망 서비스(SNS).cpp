#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>>v;
vector<vector<int>>t;
int dp[1000001][2];//인덱스ㅡ노드종류
//얼리어답터라면 자식이 두가지 종류가 올수 있지만
//아니라면 자식은 무조건 얼리어답터가 와야한다.
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
int go(int cur,int type) {//부모노드 type 0 일반노드 1 얼리어답터
	int &res = dp[cur][type];
	if (res != -1) return res;

	if (type == 0) {//부모가 일반노드였다면 현재노드는 무조건 얼리어답터 노드
		res = 0;
		for (int i = 0; i < t[cur].size(); i++) {
			int next = t[cur][i];
			res += go(next, 1);
		}
	}
	else if(type ==1) {//부모가 얼리어답터였다면 두가지 모두 가능함
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
	//양방향그래프를 트리로 만들어줌
	make_tree(1);

	printf("%d\n", min(go(1, 0), go(1, 1)));
	return 0;
}