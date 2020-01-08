#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
vector<vector<int>>v;
queue<int>q;
int chk[101];
int bfs() {
	memset(chk, 0, sizeof(chk));
	q.push(0);
	chk[0] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (chk[next] == 0) {
				chk[next] = 1;
				q.push(next);
			}
		}
	}
	if (chk[99]) return 1;
	else return 0;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tt = 10;
	for (int t = 1; t <= tt; t++) {
		int tmp, n; cin >> tmp>> n;
		v.resize(101);
		for (int i = 0; i < n; i++) {
			int a, b; cin >> a >> b;
			v[a].push_back(b);
		}
		cout << "#" << t << " " << bfs() << "\n";
		v.clear();
	}
	return 0;
}