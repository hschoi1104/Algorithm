#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int n, m, shark_num, king_pos = 0, ans, dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
struct node {
	int y, x, s, d, z;
	bool operator < (const node& tmp) const {
		return z > tmp.z;
	}
};
vector<vector<set<node>>> arr;
vector<node>shark;

bool cmp(const node& a, const node& b) {
	return a.z > b.z;
}
void init() {
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) arr[i][j].clear();
	for (auto it : shark) arr[it.y][it.x].insert(it);
	shark.clear();
}
node move(node cur) {
	int t;
	if (cur.d == 0 || cur.d == 2) t = cur.s %= (2 * m - 2);
	else t = cur.s %= (2 * n - 2);
	while (t--) {
		int ny = cur.y + dir[cur.d][0], nx = cur.x + dir[cur.d][1];
		if (0 < ny && ny <= n && 0 < nx && nx <= m) {
			cur.y = ny; cur.x = nx;
		}
		else {
			cur.d += 2;
			cur.d %= 4;
			ny = cur.y + dir[cur.d][0], nx = cur.x + dir[cur.d][1];
			cur.y = ny; cur.x = nx;
		}
	}
	return cur;
}
int solve() {
	while (king_pos <= m) {
		king_pos += 1;
		if (king_pos > m) break;
		init();
		//상어잡기
		for (int i = 1; i <= n; i++) if (arr[i][king_pos].size() != 0) {
			ans += arr[i][king_pos].begin()->z;
			arr[i][king_pos].clear();
			break;
		}
		//상어이동
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (!arr[i][j].empty()) {
					node curShark = *arr[i][j].begin();
					node res = move(curShark);
					shark.push_back(res);
				}
			}
		}
	}
	return ans;
}
int main() {
	FIO;
	cin >> n >> m >> shark_num;
	for (int i = 0; i < shark_num; i++) {
		node tmp;
		cin >> tmp.y >> tmp.x >> tmp.s >> tmp.d >> tmp.z;
		if (tmp.d == 1) tmp.d = 3;
		else if (tmp.d == 2) tmp.d = 1;
		else if (tmp.d == 3) tmp.d = 0;
		else tmp.d = 2;
		shark.push_back(tmp);
	}
	arr.resize(n + 1);
	for (int i = 0; i <= n; i++) arr[i].resize(m + 1);
	cout << solve();
	return 0;
}