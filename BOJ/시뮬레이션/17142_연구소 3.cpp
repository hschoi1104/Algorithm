#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
struct pos {
	int y, x;
};
int n, m, arr[51][51], brr[51][51], orderchk[11], chk[51][51], dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} }, ans = INT_MAX;
vector <pos> virus;
queue<pos>q;

int chkbrr() {
	//chk
	int tmp = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		if (arr[i][j] == 0 && chk[i][j] == 0) return INT_MAX;
		if (arr[i][j] == 1||arr[i][j] == 2) continue;
		tmp = max(tmp, chk[i][j]);
	}
	return (tmp-1==-1?0:tmp-1);
}
int bfs() {
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) brr[i][j] = arr[i][j];
	memset(chk, 0, sizeof(chk));
	for (int i = 0; i < 11; i++) if (orderchk[i]) {
		q.push(virus[i]);
		brr[virus[i].y][virus[i].x] = 0;
		chk[virus[i].y][virus[i].x] = 1;
	}

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = cur.y + dir[k][0], nx = cur.x + dir[k][1];
			if (0 <= ny && ny < n && 0 <= nx && nx < n && chk[ny][nx] == 0 && (brr[ny][nx] == 0||brr[ny][nx]==2)) {
				chk[ny][nx] = chk[cur.y][cur.x] + 1;
				q.push({ ny,nx });
			}
		}
	}
	return chkbrr();
}
void solve(int cur, int dep) {
	if (dep == m) {
		ans = min(ans, bfs());
		return;
	}
	for (int i = cur; i < virus.size(); i++) {
		if (orderchk[i] == 0) {
			orderchk[i] = 1;
			solve(i, dep + 1);
			orderchk[i] = 0;
		}
	}
	return;
}
int main() {
	FIO;
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		cin >> arr[i][j];
		if (arr[i][j] == 2) virus.push_back({ i,j });
	}

	solve(0, 0);
	cout << (ans >= INT_MAX ? -1 : ans);
	return 0;
}