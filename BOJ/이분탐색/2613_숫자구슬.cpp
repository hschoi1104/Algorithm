#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
vector<int>v;
int ans = INT_MAX, ansmid = 0;
int main() {
	//input
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x; cin >> x; v.push_back(x);
	}
	//binary search
	int l = 0, r = INT_MAX;
	while (l < r) {
		int mid = (l + r) / 2;
		int tans = 0, tmp = 0, cnt = 0;
		for (auto it : v) {
			//tmp+it이 mid를 넘을떄
			if (tmp + it > mid) {
				bool flag = false;
				if (tmp == 0) {
					flag = true;
					tmp = it;
				}
				cnt++;
				tans = max(tans, tmp);
				tmp = 0;
				if (flag)continue;
				else tmp += it;
			}
			//넘지 않을때
			else tmp += it;
		}
		if (tans != 0) {
			tans = max(tans, tmp);
			cnt++;
		}
		if (cnt > m) {
			l = mid + 1;
		}h
		else {
			if (cnt == m) {
				ans = min(ans, tans);
				if (ans == tans)ansmid = mid;
			}
			r = mid - 1;
		}
	}
	//output
	cout << ans << "\n";
	int tmp = 0, cnt = 0;
	for (auto it : v) {
		if (tmp + it > ansmid) {
			if (tmp == 0) {
				cout << 1 << " ";
			}
			else {
				cout << cnt << " ";
				tmp = cnt = 0;
				tmp += it;
				cnt++;
			}
		}
		else {
		tmp += it; cnt++;
		}
	}
	if(cnt!=0) cout << cnt;
	return 0;
}