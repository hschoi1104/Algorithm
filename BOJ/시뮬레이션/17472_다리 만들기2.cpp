#include <iostream>
#include <queue>
using namespace std;
int n, m, c = 1, arr[11][11], label[11][11], par[7], dir[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };//©ч,╩С,©Л,го
typedef struct pos {
	int y, x, d;
	bool operator <(const pos& p) const {
		return d > p.d;
	}
};
priority_queue<pos> pq;
bool chk(int ny, int nx) {
	return 0 <= ny && ny < n && 0 <= nx && nx < m;
}
int find(int u) {
	if (par[u] == u) return u;
	return par[u] = find(par[u]);
}
void _union(int v, int u) {
	v = find(v), u = find(u);
	par[v] = u;
}
int kruskal() {
	if (pq.size() < c - 2) return -1;
	int cnt = 0, sum = 0;
	while (!pq.empty() && cnt != c - 2) {
		auto cur = pq.top();
		pq.pop();
		if (find(cur.y) != find(cur.x)) {
			sum += cur.d, cnt++;
			_union(cur.y, cur.x);
		}
	}
	return cnt != c - 2 ? -1 : sum;
}
void findLoad(pos s, int cur, int kd) {
	int ny = s.y, nx = s.x, d = 0;
	while (1) {
		if (0 > ny || ny >= n || 0 > nx || nx >= m) break;
		if (label[ny][nx] == cur) break;
		else if (label[ny][nx] != cur && label[ny][nx]) {
			if (d != 1) pq.push(pos{ cur,label[ny][nx],d });
			break;
		}
		ny += dir[kd][0], nx += dir[kd][1];
		d += 1;
	}
	return;
}
void labeling(pos s, int cnt) {
	queue<pos>q;
	q.push(s);
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		label[s.y][s.x] = cnt;
		for (int k = 0; k < 4; k++) {
			int ny = cur.y + dir[k][0], nx = cur.x + dir[k][1];
			if (chk(ny, nx) && arr[ny][nx] == 1 && !label[ny][nx]) {
				label[ny][nx] = cnt;
				q.push(pos{ ny,nx });
			}
		}
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> arr[i][j];

	for (int i = 0; i < 7; i++) par[i] = i;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] && !label[i][j]) {
				labeling(pos{ i,j }, c);
				c++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (label[i][j]) {
				for (int k = 0; k < 4; k++) {
					int ny = i + dir[k][0], nx = j + dir[k][1];
					if (chk(ny, nx) && !label[ny][nx]) {
						findLoad(pos{ ny,nx }, label[i][j], k);
					}
				}
			}
		}
	}
	cout << kruskal();
	return 0;
}