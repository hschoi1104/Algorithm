#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n,x,ans=0,cnt=1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	for (auto it : v) {
		if (it >= cnt) {
			cnt += 1;
			ans += 1;
		}
		else continue;
	}
	cout << ans;
	return 0;
}