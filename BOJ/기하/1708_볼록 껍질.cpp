#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
vector<p> uh(100001), dh(100001);
vector<p> v;
int di, ui;
ll ccw(p a, p b, p c) {
	return (a.first * b.second + b.first * c.second + c.first * a.second) - (b.first * a.second + c.first * b.second + a.first * c.second);
}
int ConvexHull() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		while (di > 1 && ccw(dh[di - 2], dh[di - 1], v[i]) >= 0) di--;
		while (ui > 1 && ccw(uh[ui - 2], uh[ui - 1], v[i]) <= 0) ui--;
		dh[di++] = uh[ui++] = v[i];
	}
	return di + ui - 2;
}
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}

	cout << ConvexHull();
	return 0;
}