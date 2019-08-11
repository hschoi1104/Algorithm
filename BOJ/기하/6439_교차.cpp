#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<p, p> pp;
vector<p>v;
int ccw(p a, p b, p c) {
	int res = (a.first * b.second + b.first * c.second + c.first * a.second) - (b.first * a.second + c.first * b.second + a.first * c.second);
	if (res > 0) return 1;
	else if (res < 0) return -1;
	else return 0;
}
bool isIntersect(p a, p b, p c, p d) {
	ll ccwA = ccw(a, b, c) * ccw(a, b, d);
	ll ccwB = ccw(c, d, a) * ccw(c, d, b);
	if (ccwA == 0 && ccwB == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		if (a > c) {
			swap(a, c);
			swap(b, d);
		}
		if (c <= b && b <= d) return true;
		else return false;
	}
	if (ccwA <= 0 && ccwB <= 0) return true;
	else return false;
}
int main() {
	int t; cin >> t;
	while (t--) {
		int a, b, c, d, e, f, g, h;
		cin >> a >> b >> c >> d >> e >> f >> g >> h;
		p start = { a,b }, end = { c,d };
		if (a > c) swap(start, end);
		if (e > g) swap(e, g);
		//선분 내부에 존재
		if (e <= start.first && end.first <= g && max(f, h) >= max(start.second, end.second) && min(f, h) <= min(start.second, end.second)) {
			cout << "T\n";
			continue;
		}

		vector<pp>v;
		v.push_back({ {e,f},{e,h} });
		v.push_back({ {e,h},{g,h} });
		v.push_back({ {g,h},{g,f} });
		v.push_back({ {g,f},{e,f} });
		bool chk = false;
		for (int i = 0; i < v.size(); i++) {
			bool res = isIntersect(v[i].first, v[i].second, start, end);
			if (res == true) {
				cout << "T\n";
				chk = true;
				break;
			}
		}
		if (chk == false) cout << "F\n";
	}
	return 0;
}