#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool chk[2001][2001];
typedef struct Node {
	int time, clip, disply;
}node;
struct cmp {
	bool operator()(node t, node u) {
		return t.time > u.time;
	}
};
priority_queue<node, vector<node>, cmp> pq;
int go(int n) {
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (cur.disply >= 2001) continue;
		if (cur.disply == n) return cur.time;
		if (!chk[cur.disply][cur.disply]) {
			pq.push(node{ cur.time + 1,cur.disply,cur.disply });
			chk[cur.disply][cur.disply] = true;
		}
		if (cur.disply + cur.clip <= 2001 && !chk[cur.clip][cur.disply + cur.clip] && cur.clip) {
			pq.push(node{ cur.time + 1,cur.clip,cur.disply + cur.clip });
			chk[cur.clip][cur.disply + cur.clip] = true;
		}
		if (cur.disply > 1 && !chk[cur.clip][cur.disply - 1]) {
			pq.push(node{ cur.time + 1,cur.clip,cur.disply - 1 });
			chk[cur.clip][cur.disply - 1] = true;
		}
	}
	return 0;
}
int main() {
	int n; cin >> n;
	pq.push(node{ 0,0,1 });
	cout << go(n);
	return 0;
}