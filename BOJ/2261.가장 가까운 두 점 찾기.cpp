#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <math.h>
using namespace std;
typedef pair<int, int> pp;
vector<pp> p;
set<pp>s;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		p.push_back({ a,b });
	}
	sort(p.begin(), p.end());
	int d = (p[0].first - p[1].first) * (p[0].first - p[1].first) + (p[0].second - p[1].second) * (p[0].second - p[1].second);
	s.insert({ p[0].second,p[0].first }); s.insert({ p[1].second,p[1].first });
	int pos = 0;
	for (int i = 2; i < n; i++) {
		auto now = p[i];
		for (int j = pos; j < i; j++) {
			if ((p[i].first - p[j].first) * (p[i].first - p[j].first) > d) {
				s.erase(pp(p[j].second, p[j].first));
				pos++;
			}
			else break;
		}
		int dist = (int)sqrt((double)d) + 1;
		auto lower = s.lower_bound(pp(now.second - dist, -100000));
		auto upper = s.upper_bound(pp(now.second + dist, 100000));
		for (auto it = lower; it != upper; it++) {
			d = min(d, (now.first - it->second) * (now.first - it->second) + (now.second - it->first) * (now.second - it->first));
		}
		s.insert({ now.second,now.first });
	}
	cout << d;
	return 0;
}