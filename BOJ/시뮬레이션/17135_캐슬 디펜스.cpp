#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef struct enemy {
	int d, y, x;
	bool operator < (const enemy &tmp) const{
		if (d == tmp.d) return x > tmp.x;
		else return d > tmp.d;
	}
}enemy;
int map[16][16], tmap[16][16], archer[3], n, m, d, ans = 0;
void copy() {
	for (int i = 0; i <= n; i++)for (int j = 0; j < m; j++)tmap[i][j] = map[i][j];
}
void move() {
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j < m; j++) {
			tmap[i + 1][j] = tmap[i][j];
			if (i == 0) tmap[i][j] = 0;
		}
	}
	return;
}
void go() {
	copy();
	int c = n,tans =0;
	while (c--) {
		//공격대상 지정
		vector<enemy> en;
		for (int k = 0; k < 3; k++) {
			priority_queue<enemy>pq;
			for (int i = n - 1; i >= 0; i--) {
				for (int j = 0; j < m; j++) {
					if (tmap[i][j]) {
						int dist = abs(i - n) + abs(j - archer[k]);
						if (dist <= d) pq.push(enemy{ dist,i,j });
					}
				}
			}
			if(!pq.empty()) en.push_back(pq.top());
		}
		//중복제거 및 적 제거
		for (auto it : en) {
			if (tmap[it.y][it.x]) {
				tans += 1;
				tmap[it.y][it.x] = 0;
			}
		}
		//적이동
		move();
	}
	ans = max(ans, tans);
}
void setArcher(int c,int pos) {
	if (c == 3) {
		go();
		return;
	}
	for (int i = pos; i < m; i++) {
		if (!map[n][i]) {
			map[n][i] = 1;
			archer[c] = i;
			setArcher(c + 1,i);
			map[n][i] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> map[i][j];
	setArcher(0,0);
	cout << ans;
	return 0;
}