#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
struct pos {
	int y, x, d;
};
int a[13][13], n, k, turn, dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
vector<vector<deque<int>>> b;
vector<pos>toy;


void input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
	for (int i = 0; i < k; i++) {
		pos tmp;
		cin >> tmp.y >> tmp.x >> tmp.d;
		if (tmp.d == 1) tmp.d = 0;
		if (tmp.d == 4) tmp.d = 1;
		tmp.y -= 1;
		tmp.x -= 1;
		toy.push_back(tmp);
	}
}
bool chk() {
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (b[i][j].size() >= 4) return true;
	return false;
}
void move(pos cur, int num) {
	int ny = cur.y + dir[cur.d][0], nx = cur.x + dir[cur.d][1];
	int state = (0 <= ny && ny < n && 0 <= nx && nx < n ? a[ny][nx] : 2);
	//흰색으로 이동
	if (state == 0) {
		//임시저장
		deque<int>tmp;
		while (1) {
			if (!tmp.empty() && tmp.back() == num) break;
			if (!b[cur.y][cur.x].empty()) {
				tmp.push_back(b[cur.y][cur.x].back());
				b[cur.y][cur.x].pop_back();
			}
		}
		//이동
		while(!tmp.empty()){
			auto it = tmp.back();
			tmp.pop_back();
			toy[it - 1] = { ny,nx,toy[it-1].d};
			b[ny][nx].push_back(it);
		}
		tmp.clear();
	}
	//빨간색
	else if (state == 1) {
		//임시저장
		while (1) {
			if (!b[ny][nx].empty() && b[ny][nx].back() == num) break;
			if (!b[cur.y][cur.x].empty()) {
				b[ny][nx].push_back(b[cur.y][cur.x].back());
				toy[b[cur.y][cur.x].back() - 1] = { ny,nx,toy[b[cur.y][cur.x].back()-1].d };
				b[cur.y][cur.x].pop_back();
			}
		}
	}
	//파란색 or 갈수없음
	else if (state == 2) {
		//방향 바꿈
		cur.d = (cur.d + 2) % 4;
		toy[num - 1].d = cur.d;
		ny = cur.y + dir[cur.d][0], nx = cur.x + dir[cur.d][1];
		int state2 = (0 <= ny && ny < n && 0 <= nx && nx < n ? a[ny][nx] : 2);
		if (state2 != 2) move(cur, num);
	}
	return;
}
int solve() {
	//턴 수가 1000이하까지 반복
	while (turn <= 1000) {
		turn += 1;
		//모든 말 이동
		for (int i = 0; i < toy.size(); i++) {
			move(toy[i], i + 1);
			if (chk()) return turn;
		}
	}
	return -1;
}
void init() {
	//격자 deq resize
	b.resize(n);
	for (int i = 0; i < n; i++) b[i].resize(n);
	//격자에 위치시킴
	for (int i = 0; i < toy.size(); i++)
		b[toy[i].y][toy[i].x].push_back(i + 1);
}
int main() {
	FIO;
	input();
	init();
	cout << solve();
	return 0;
}