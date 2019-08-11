#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> p;
char arr[51][51];
int chk[51][51];
int pchk[251];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
p s;
vector<p>keys;
vector<vector<p>>g;
int n, m, ans = 0;

int prim() {
	priority_queue<p, vector<p>, greater<p>> pq;//거리,정점
	pq.push({ 0,1 });
	while (!pq.empty()) {
		p cur = pq.top();
		pq.pop();
		if (pchk[cur.second]) continue;
		else pchk[cur.second] = 1;
		ans += cur.first;
		for (int i = 0; i < g[cur.second].size(); i++) {
			p next = g[cur.second][i];
			if (!pchk[next.second]) pq.push(next);
		}
	}
	return ans;
}

void bfs(p st) {
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) chk[i][j] = -1;
	queue<p>q;
	q.push(st);
	chk[st.first][st.second] = 0;
	while (!q.empty()) {
		p cur = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int dy = cur.first + dir[k][0];
			int dx = cur.second + dir[k][1];
			if (0 <= dy && dy < n && 0 <= dx && dx < n && arr[dy][dx] != '1' && chk[dy][dx] == -1) {
				q.push({ dy,dx });
				chk[dy][dx] = chk[cur.first][cur.second] + 1;
			}
		}
	}

}
bool chkkey() {
	for (int i = 0; i < keys.size(); i++) {
		if (chk[keys[i].first][keys[i].second] == -1) return false;
	}
	return true;
}
int main() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %1c", &arr[i][j]);
			if (arr[i][j] == 'S') s = { i,j };
			else if (arr[i][j] == 'K') {
				keys.push_back({ i,j });
			}
		}
	}
	g.resize(keys.size() + 2);
	bfs(s);
	if (!chkkey()) {
		printf("-1");
		return 0;
	}
	keys.push_back(s);
	for (int i = 0; i < keys.size(); i++) {
		bfs(keys[i]);
		for (int j = 0; j < keys.size(); j++) {
			if (i == j) continue;
			g[i + 1].push_back({ chk[keys[j].first][keys[j].second],j + 1 });
		}
	}
	printf("%d", prim());
	return 0;
}