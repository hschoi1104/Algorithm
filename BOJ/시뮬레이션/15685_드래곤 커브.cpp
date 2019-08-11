#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef pair<pair<int, int>, int> pp;
typedef pair<int, int> p;
set<p>s;
set < pair<p, p>> chkset;
int dir[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };
int rdir[9][2] = { {0,0}, {-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0} };
int ans = 0;
p move(p a, int k) {
	return { a.first + dir[k][0],a.second + dir[k][1] };
}
int change(int k) {
	k = k + 1;
	if (k == 4) k = 0;
	return k;
}
void chk(p cur) {
	bool res[9] = { false };
	for (int i = 1; i <= 8; i++) {
		if (s.find({ cur.first + rdir[i][0],cur.second + rdir[i][1] }) != s.end()) {
			res[i] = true;
		}
	}
	if (res[1] && res[2] && res[8]) {
		if (chkset.find({ {cur.first + rdir[1][0],cur.first + rdir[2][0]},{cur.second + rdir[1][1],cur.second + rdir[8][1] } }) == chkset.end()) {
			chkset.insert({ {cur.first + rdir[1][0],cur.first + rdir[2][0]},{cur.second + rdir[1][1],cur.second + rdir[8][1] } });
			ans += 1;
		}
	}
	if (res[2] && res[3] && res[4]) {
		if (chkset.find({ {cur.first + rdir[2][0],cur.first + rdir[3][0]},{cur.second + rdir[3][1],cur.second + rdir[4][1] } }) == chkset.end()) {
			chkset.insert({ {cur.first + rdir[2][0],cur.first + rdir[3][0]},{cur.second + rdir[3][1],cur.second + rdir[4][1] } });
			ans += 1;
		}
	}
	if (res[4] && res[5] && res[6]) {
		if (chkset.find({ {cur.first + rdir[6][0],cur.first + rdir[5][0]},{cur.second + rdir[4][1],cur.second + rdir[5][1] } }) == chkset.end()) {
			chkset.insert({ {cur.first + rdir[6][0],cur.first + rdir[5][0]},{cur.second + rdir[4][1],cur.second + rdir[5][1] } });
			ans += 1;
		}
	}
	if (res[6] && res[7] && res[8]) {
		if (chkset.find({ {cur.first + rdir[8][0],cur.first + rdir[6][0]},{cur.second + rdir[8][1],cur.second + rdir[6][1] } }) == chkset.end()) {
			chkset.insert({ {cur.first + rdir[8][0],cur.first + rdir[6][0]},{cur.second + rdir[8][1],cur.second + rdir[6][1] } });
			ans += 1;
		}
	}
}
int main() {
	int n, x, y, d, g;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		vector<pp>v;
		scanf("%d %d %d %d", &x, &y, &d, &g);
		s.insert({ y,x });
		v.push_back({ move({ y,x }, d),d });
		s.insert(move({ y,x }, d));
		for (int j = 0; j < g; j++) {
			for (int p = v.size() - 1; p >= 0; p--) {
				pp next = { move(v[v.size() - 1].first, change(v[p].second)),change(v[p].second) };
				v.push_back({ next.first , next.second });
				s.insert({ next.first });
			}
		}
	}

	for (auto it = s.begin(); it != s.end(); it++) {
		chk(*it);
	}
	printf("%d", ans);
	return 0;
}