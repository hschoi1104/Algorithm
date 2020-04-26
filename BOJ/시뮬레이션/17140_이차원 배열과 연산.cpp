#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define IFOR(a,b) for(int i=a;i<b;i++)
#define JFOR(a,b) for(int j=a;j<b;j++)
using namespace std;
int r, c, k, a[110][110], max_r, max_c, chk[101];
struct node {
	int n, cnt;
	bool operator <(const node& tmp)const {
		if (cnt == tmp.cnt) return n < tmp.n;
		else return cnt < tmp.cnt;
	}
};
vector<node>v;
void init() {
	IFOR(1, 101)chk[i] = 0;
	v.clear();
}
void C() {
	int tmp_r = 0;
	IFOR(0, max_c) {
		init();
		JFOR(0, max_r) chk[a[j][i]] += 1;
		JFOR(1, 101) if (chk[j]) v.push_back({ j,chk[j] });
		sort(v.begin(), v.end());
		JFOR(0, v.size()) {
			if (j == 50) break;
			a[j * 2][i] = v[j].n;
			a[j * 2 + 1][i] = v[j].cnt;
			tmp_r = max(tmp_r, j * 2 + 2);
		}
		JFOR(v.size() * 2, 100) a[j][i] = 0;
	}
	max_r = tmp_r;
	return;
}
void R() {
	int tmp_c = 0;
	IFOR(0, max_r) {
		init();
		JFOR(0, max_c) chk[a[i][j]] += 1;
		JFOR(1, 101) if (chk[j]) v.push_back({ j,chk[j] });
		sort(v.begin(), v.end());
		JFOR(0, v.size()) {
			if (j == 50) break;
			a[i][j * 2] = v[j].n;
			a[i][j * 2 + 1] = v[j].cnt;
			tmp_c = max(tmp_c, j * 2 + 2);
		}
		JFOR(v.size() * 2, 100) a[i][j] = 0;
	}
	max_c = tmp_c;
	return;
}
int solve() {
	if (a[r][c] == k) return 0;
	int t = 100;
	while (t--) {
		if (max_r >= max_c) R();
		else C();
		if (a[r][c] == k) return 100 - t;
	}
	return -1;
}

int main() {
	FIO;
	cin >> r >> c >> k;
	IFOR(0, 3)JFOR(0, 3) cin >> a[i][j];
	r -= 1; c -= 1;
	max_r = max_c = 3;
	cout << solve();
	return 0;
}

//#include <bits/stdc++.h>
//
//#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//#define IFOR(a,b) for(int i=a;i<b;i++)
//#define JFOR(a,b) for(int j=a;j<b;j++)
//using namespace std;
//int r, c, k, a[110][110], mr, mc, chk[101];
//struct node {
//	int n, cnt;
//	bool operator <(const node& tmp)const {
//		if (cnt == tmp.cnt) return n < tmp.n;
//		return cnt < tmp.cnt;
//	}
//};
//vector<node>v;
//
//void P(int ty) {
//	int tmp = 0, trg = (ty ? mr : mc), trg2 = (ty ? mc : mr);
//	IFOR(0, trg) {
//		IFOR(1, 101)chk[i] = 0;
//		v.clear();
//		JFOR(0, trg2) (ty ? chk[a[i][j]] : chk[a[j][i]]) += 1;
//		JFOR(1, 101) if (chk[j]) v.push_back({ j,chk[j] });
//		sort(v.begin(), v.end());
//		JFOR(0, v.size()) {
//			if (j == 50) break;
//			(ty ? a[i][j * 2] : a[j * 2][i]) = v[j].n;
//			(ty ? a[i][j * 2 + 1] : a[j * 2 + 1][i]) = v[j].cnt;
//			tmp = max(tmp, j * 2 + 2);
//		}
//		JFOR(v.size() * 2, 100)(ty ? a[i][j] : a[j][i]) = 0;
//	}
//	(ty ? mc : mr) = tmp;
//	return;
//}
//int main() {
//	FIO;
//	cin >> r >> c >> k;
//	IFOR(0, 3)JFOR(0, 3) cin >> a[i][j];
//	r -= 1; c -= 1;
//	mr = mc = 3;
//	int t = 101;
//	while (t--) {
//		if (a[r][c] == k) {
//			cout << 100 - t;
//			return 0;
//		}
//		(mr >= mc ? P(1) : P(0));
//	}
//	cout << -1;
//	return 0;
//}