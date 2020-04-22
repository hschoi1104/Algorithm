#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define END 32
using namespace std;
vector<vector<int>>v;
vector<int>dice;
int ans = 0, isFinish[5], curPos[5], moveOrder[11], point[41] = { 0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,13,16,19,25,26,27,28,22,24,30,35,0 };
void makeG() {
	v.resize(35);
	for (int i = 0; i < 20; i++) v[i].push_back(i + 1);

	v[5].push_back(21);
	for (int i = 21; i <= 23; i++) v[i].push_back(i + 1);
	for (int i = 25; i <= 27; i++) v[i].push_back(i - 1);
	v[15].push_back(27);

	v[10].push_back(28);
	for (int i = 28; i <= 30; i++) {
		if (i == 29) {
			v[i].push_back(24);
			v[24].push_back(30);
		}
		else v[i].push_back(i + 1);
	}
	v[31].push_back(20);
	v[20].push_back(32);
}
void input() {
	dice.resize(10);
	for (int i = 0; i < 10; i++) cin >> dice[i];
}
void init() {
	memset(isFinish, 0, sizeof(isFinish));
	memset(curPos, 0, sizeof(curPos));
	return;
}
//이동가능한지 체크
int canMove(int num, int s, int diceNum) {
	if (s == 5 || s == 10 || s == 15) {
		s = v[s][1];
		diceNum--;
	}
	while (diceNum--) {
		s = v[s][0];
		if (s == END) break;
	}
	if (s == 32) return s;
	for (int i = 1; i <= 4; i++) {
		if (i == num) continue;
		if (curPos[i] == s) return -1;
	}
	return s;
}
int move() {
	init();
	int score = 0;
	for (int i = 0; i < 10; i++) {
		if (isFinish[moveOrder[i]]) continue;
		int res = canMove(moveOrder[i], curPos[moveOrder[i]], dice[i]);
		if (res == -1) return 0;
		else if (res == END) isFinish[moveOrder[i]] = 1;

		curPos[moveOrder[i]] = res;
		if (res != END) score += point[res];
	}
	return score;
}
void findOrder(int depth) {
	if (depth == 10) {
		ans = max(ans, move());
		return;
	}
	for (int i = 1; i <= 4; i++) {
		moveOrder[depth] = i;
		findOrder(depth + 1);
		moveOrder[depth] = 0;
	}
	return;
}
int main() {
	FIO;
	input();
	makeG();
	findOrder(0);
	cout << ans;
	return 0;
}