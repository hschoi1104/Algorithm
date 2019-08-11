#include <stdio.h>
#include <deque>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
vector<deque<int>>geer;
int chk[5];
void turn(int name, int dir) {
	//오른쪽
	chk[name] = 1;
	if (name + 1 <= 4 && chk[name + 1] == 0 && geer[name][2] != geer[name + 1][6]) {
		turn(name + 1, dir*(-1));
	}
	//왼쪽
	if (name - 1 > 0 && chk[name - 1] == 0 && geer[name][6] != geer[name - 1][2]) {
		turn(name - 1, dir*(-1));
	}
	//회전
	if (dir == 1) {
		geer[name].push_front(geer[name].back());
		geer[name].pop_back();
	}
	else if (dir == -1) {
		geer[name].push_back(geer[name].front());
		geer[name].pop_front();
	}
	return;
}
int main() {
	int x, k, n, d, ans = 0;
	geer.resize(5);
	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &x);
			geer[i].push_back(x);
		}
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &n, &d);
		memset(chk, 0, sizeof(chk));
		turn(n, d);
	}

	if (geer[1][0] == 1) ans += 1;
	if (geer[2][0] == 1) ans += 2;
	if (geer[3][0] == 1) ans += 4;
	if (geer[4][0] == 1) ans += 8;
	printf("%d", ans);
	return 0;
}