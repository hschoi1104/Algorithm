#include <iostream>
#include <vector>
#include <set>
using namespace std;
int dir[4][2] = { {1,0} ,{0,-1},{-1,0},{0,1} };
typedef pair<int, int> p;
set<p>s;
void draw(int x, int y, int d, int g) {
	s.insert({ x,y });
	vector<int>v;
	v.push_back(d);
	while (g--) {
		for (int i = v.size() - 1; i >= 0; i--)
			v.push_back((v[i] + 1) % 4);
	}
	for (auto it : v) {
		x += dir[it][0]; y += dir[it][1];
		s.insert({ x,y });
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, d, g; cin >> x >> y >> d >> g;
		draw(x, y, d, g);
	}
	int ans = 0;
	for (auto it : s) {
		if (s.find({ it.first,it.second + 1 }) == s.end()) continue;
		if (s.find({ it.first + 1,it.second }) == s.end()) continue;
		if (s.find({ it.first + 1,it.second + 1 }) == s.end()) continue;
		ans += 1;
	}
	cout << ans;
	return 0;
}

// #include <stdio.h>
// #include <vector>
// #include <set>
// #include <algorithm>
// using namespace std;
// typedef pair<pair<int, int>, int> pp;
// typedef pair<int, int> p;
// set<p>s;
// set < pair<p, p>> chkset;
// int dir[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };
// int rdir[9][2] = { {0,0}, {-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0} };
// int ans = 0;
// p move(p a, int k) {
// 	return { a.first + dir[k][0],a.second + dir[k][1] };
// }
// int change(int k) {
// 	k = k + 1;
// 	if (k == 4) k = 0;
// 	return k;
// }
// void chk(p cur) {
// 	bool res[9] = { false };
// 	for (int i = 1; i <= 8; i++) {
// 		if (s.find({ cur.first + rdir[i][0],cur.second + rdir[i][1] }) != s.end()) {
// 			res[i] = true;
// 		}
// 	}
// 	if (res[1] && res[2] && res[8]) {
// 		if (chkset.find({ {cur.first + rdir[1][0],cur.first + rdir[2][0]},{cur.second + rdir[1][1],cur.second + rdir[8][1] } }) == chkset.end()) {
// 			chkset.insert({ {cur.first + rdir[1][0],cur.first + rdir[2][0]},{cur.second + rdir[1][1],cur.second + rdir[8][1] } });
// 			ans += 1;
// 		}
// 	}
// 	if (res[2] && res[3] && res[4]) {
// 		if (chkset.find({ {cur.first + rdir[2][0],cur.first + rdir[3][0]},{cur.second + rdir[3][1],cur.second + rdir[4][1] } }) == chkset.end()) {
// 			chkset.insert({ {cur.first + rdir[2][0],cur.first + rdir[3][0]},{cur.second + rdir[3][1],cur.second + rdir[4][1] } });
// 			ans += 1;
// 		}
// 	}
// 	if (res[4] && res[5] && res[6]) {
// 		if (chkset.find({ {cur.first + rdir[6][0],cur.first + rdir[5][0]},{cur.second + rdir[4][1],cur.second + rdir[5][1] } }) == chkset.end()) {
// 			chkset.insert({ {cur.first + rdir[6][0],cur.first + rdir[5][0]},{cur.second + rdir[4][1],cur.second + rdir[5][1] } });
// 			ans += 1;
// 		}
// 	}
// 	if (res[6] && res[7] && res[8]) {
// 		if (chkset.find({ {cur.first + rdir[8][0],cur.first + rdir[6][0]},{cur.second + rdir[8][1],cur.second + rdir[6][1] } }) == chkset.end()) {
// 			chkset.insert({ {cur.first + rdir[8][0],cur.first + rdir[6][0]},{cur.second + rdir[8][1],cur.second + rdir[6][1] } });
// 			ans += 1;
// 		}
// 	}
// }
// int main() {
// 	int n, x, y, d, g;
// 	scanf("%d", &n);
// 	for (int i = 0; i < n; i++) {
// 		vector<pp>v;
// 		scanf("%d %d %d %d", &x, &y, &d, &g);
// 		s.insert({ y,x });
// 		v.push_back({ move({ y,x }, d),d });
// 		s.insert(move({ y,x }, d));
// 		for (int j = 0; j < g; j++) {
// 			for (int p = v.size() - 1; p >= 0; p--) {
// 				pp next = { move(v[v.size() - 1].first, change(v[p].second)),change(v[p].second) };
// 				v.push_back({ next.first , next.second });
// 				s.insert({ next.first });
// 			}
// 		}
// 	}

// 	for (auto it = s.begin(); it != s.end(); it++) {
// 		chk(*it);
// 	}
// 	printf("%d", ans);
// 	return 0;
// }