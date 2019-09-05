#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>v;
int INF = 99999;
vector <vector<int>> s({
	vector<int>({ 0,1,2 }),
	vector<int>({ 3,7,9,11 }),
	vector<int>({ 4,10,14,15 }),
	vector<int>({ 0,4,5,6,7 }),
	vector<int>({ 6,7,8,10,12 }),
	vector<int>({ 0,2,14,15 }),
	vector<int>({ 3,14,15 }),
	vector<int>({ 4,5,7,14,15 }),
	vector<int>({ 1,2,3,4,5 }),
	vector<int>({ 3,4,5,9,13 }),
	});
void init() {
	v.clear();
}
bool chk() {
	for (auto i : v) if (i != 0) return false;
	return true;
}
void put(int i) {
	for (auto k:s[i]) {
		v[k] += 1;
		if (v[k] ==4) v[k] = 0;
	}
	return;
}
int go(int sw) {
	if (sw == 10) {
		if (chk()) return 0;
		else return INF;
	}
	int ret = INF;
	for (int i = 0; i <= 3; ++i){ 
		ret = min(ret, i + go(sw + 1));
		put(sw);
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int c; cin >> c;
	while (c--) {
		init();
		for (int i = 0; i < 16; i++) { int t; cin >> t; v.push_back(t/3%4); }
		int ret = go(0);
		cout << ((ret == INF) ? -1 : ret) << "\n";
	}
	return 0;
}