#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> p;
vector<p> v;
int arr[1001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a, b, n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
		for (int i = a; i < b; i++) arr[i] += 1;
	}
	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = v[i].first; j < v[i].second; j++) arr[j] -= 1;
		int cnt = 0;
		for (int j = 0; j <= 1000; j++) if (arr[j] >= 1) cnt += 1;
		ans = max(cnt, ans);
		for (int j = v[i].first; j < v[i].second; j++) arr[j] += 1;
	}
	cout << ans;
	return 0;
}