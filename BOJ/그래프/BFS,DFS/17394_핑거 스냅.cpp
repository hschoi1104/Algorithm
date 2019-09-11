#include <iostream>
#include <queue>
#include<algorithm>
#include <string.h>
using namespace std;
typedef pair<int, int>p;
int so[100010];
int su[100010];
int chk[1000001];
queue<p>q;
bool chkchk(int s, int a, int b) {
	if (a <= s && s <= b && so[s] == 1) return true;
	else return false;
}
int bfs(int s, int a, int b) {
	chk[s] = 1;
	q.push({ s,0 });
	if (chkchk(s,a,b)) return 0;
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		chk[cur] = 1;
		q.pop();
		if (a <= cur && cur <= b && so[cur] == 1) {
			return cnt;
		}
		if (chk[cur / 2] == 0) {
			q.push({ cur / 2,cnt + 1 });
			chk[cur / 2] = 1;
			if (chkchk(s, a, b)) return cnt+1;
		}
		if (chk[cur / 3] == 0) {
			q.push({ cur / 3 ,cnt + 1 });
			chk[cur / 3] = 1;
			if (chkchk(s, a, b)) return cnt + 1;
		}
		if (cur + 1 <= 500000 && chk[cur + 1] == 0) {
			q.push({ cur + 1 ,cnt + 1 });
			chk[cur + 1] = 1;
			if (chkchk(s, a, b)) return cnt + 1;
		}
		if (cur - 1 >= 0 && chk[cur-1]==0) {
			q.push({ cur - 1 ,cnt + 1 });
			chk[cur - 1] = 1;
			if (chkchk(s, a, b)) return cnt + 1;
		}
	}
	return -1;
}
void init() {
	memset(chk, 0, sizeof(chk));
	while (!q.empty()) q.pop();
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	//so
	fill(begin(so), end(so), 1);
	so[1] = so[0] = 0;
	for (int i = 2; i < 100010; i++) {
		if (so[i] == 0) continue;
		for (int j = 2 * i; j < 100010; j += i) so[j] = 0;
	}
	//su
	for (int i = 1; i < 100010; i++) su[i] = so[i];
	for (int i = 1; i < 100010; i++) su[i] += su[i - 1];

	while (t--) {
		int n, a, b; cin >> n >> a >> b;
		if (su[b] - su[a - 1] == 0) { cout << "-1\n"; continue; }
		else {
			init();
			cout << bfs(n, a, b) << "\n";
		}
	}
	return 0;
}