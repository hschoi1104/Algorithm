#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> p;
vector<int>v;
vector<p> boots;
queue<p>q;
int x, n, b;
int chk[251][251];
int go() {
	for (int i = 0; i < b; i++) q.push({ 0,i });
	q.push({ 0,0 });

	int ans = 999999;
	while (!q.empty()) {
		int pos = q.front().first;
		int idx = q.front().second;
		q.pop();
		if (pos == n - 1) ans = min(idx, ans);
		//if (chk[pos][idx] == 1) continue;
		chk[0][0] = 1;
		//그냥 가는 경우
		for (int k = pos + 1; k < n && k - pos <= boots[idx].second; k++) {
			if (chk[k][idx] == 1) continue;

			if (v[k] <= boots[idx].first) {
				q.push({ k,idx });
				chk[k][idx] = 1;
			}
			if (k == n - 1) ans = min(idx, ans);

		}
		//신발바꿈
		for (int k = idx + 1; k < b; k++) {
			if (chk[pos][k] == 0 && v[pos] <= boots[k].first) {
				q.push({ pos, k });
				chk[pos][k] = 1;
			}
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> b;
	for (int i = 0; i < n; i++) {
		cin >> x; v.push_back(x);
	}
	for (int i = 0; i < b; i++) {
		int a, b; cin >> a >> b;
		boots.push_back({ a,b });
	}
	cout << go();
	return 0;
}