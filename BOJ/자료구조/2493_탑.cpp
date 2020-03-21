#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <functional>
#define FIO ios_base::sync_with_stdio(0), cin.tie(), cout.tie();
using namespace std;
typedef pair<int, int> p;
stack<p>a;
vector<int>v;
priority_queue<p, vector<p>, greater<p>>b;

int main() {
	FIO;
	int n; cin >> n;
	v.resize(n + 2);
	for (int i = 0; i < n; i++) {
		int x; cin >> x; a.push({ x,i + 1 });
	}
	while (!a.empty()) {
		auto cur = a.top();
		a.pop();
		if (a.empty()) break;
		if (cur.first > a.top().first) {
			b.push(cur);
			continue;
		}
		b.push(cur);
		while (!b.empty()) {
			if (a.top().first > b.top().first) {
				v[b.top().second] = a.top().second;
				b.pop();
			}
			else break;
		}
	}
	for (int i = 1; i <= n; i++) cout << v[i] << " ";
	return 0;
}