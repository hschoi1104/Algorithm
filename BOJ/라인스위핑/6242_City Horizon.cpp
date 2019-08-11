#include <stdio.h>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include  <functional>
using namespace std;
typedef long long ll;
vector<pair<pair<int, int>, int>>v; // 인덱스,시작/끝, 높이
multiset<int, greater<int>>s;//건물의 높이
int lastIndex, curIndex;
ll ans = 0;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v.push_back({ {a,1},c });
		v.push_back({ { b,0 },c });
	}
	sort(v.begin(), v.end());
	auto prev = v[0];
	auto cur = v[0];
	for (int i = 0; i < v.size(); i++) {
		if (i == 0) {
			cur = v[i];
			curIndex = cur.first.first;
			s.insert(prev.second);
			continue;
		}
		prev = cur;
		lastIndex = curIndex;
		cur = v[i];
		curIndex = cur.first.first;
		if (s.size() != 0)ans += (long long)(curIndex - lastIndex)*(*s.begin());
		if (cur.first.second == 0) s.erase(s.find(cur.second));
		if (cur.first.second == 1) s.insert(cur.second);
	}
	printf("%lld\n", ans);
	return 0;
}