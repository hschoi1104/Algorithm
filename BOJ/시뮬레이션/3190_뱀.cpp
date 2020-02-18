#include <iostream>
#include <deque>
#include <string>
using namespace std;
int arr[101][101], dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} }, n, k, l, x, t = 0;
string c;
typedef struct point {
	int y, x, d;
};
deque<point>dq;
bool move() {
	point next = dq.back();
	next.y += dir[next.d][0]; next.x += dir[next.d][1];
	if (0 < next.y && next.y <= n && 0 < next.x && next.x <= n) {
		for (auto it : dq) if (it.y == next.y && it.x == next.x) return false;
		if (!arr[next.y][next.x]) dq.pop_front();
		else arr[next.y][next.x] = 0;
		dq.push_back(next);
		return true;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	dq.push_back(point{ 1,1,0 });
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int a, b; cin >> a >> b; arr[a][b] = 1;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		cin >> x >> c;
		while (x > t) {
			t++;
			if (!move()) {
				cout << t;
				return 0;
			}
		}
		if (c == "D") {
			dq.back().d += 1;
			if (dq.back().d >= 4) dq.back().d -= 4;
		}
		else {
			dq.back().d -= 1;
			if (dq.back().d < 0) dq.back().d += 4;
		}
	}
	do {
		t++;
	} while (move());
	cout << t;
	return 0;
}