#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> p; // s0 e1
vector<p>v;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b, n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a,0 });
		v.push_back({ b,1 });
	}
	int s, e;
	s = 0; e = 100001;
	for (auto it : v) {
		//끝점중 제일 작은거
		if (it.second == 1) e = min(e, it.first);
		//시작점 중 제일 큰거
		if (it.second == 0) s = max(s, it.first);
	}
	if (s - e <= 0) cout << 0;
	else cout << s - e;
	return 0;
}