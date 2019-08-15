#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector < pair<int, pair<string, int>>>v;
int arr[27], a, b, n, res = 111, ans = 0;
string s;
int calc() {
	int val = max(arr['B' - 65], max(arr['E' - 65], arr['M' - 65]));
	int res = 0;
	if (arr['B' - 65] == val) res += 100;
	if (arr['E' - 65] == val) res += 10;
	if (arr['M' - 65] == val) res += 1;
	return res;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> s >> b;
		v.push_back({ a,{s,b} });
	}
	sort(v.begin(), v.end());
	arr['B' - 65] = arr['E' - 65] = arr['M' - 65] = 7;
	for (auto it : v) {
		arr[it.second.first[0] - 65] += it.second.second;
		int temp = calc();
		if (res == temp) continue;
		else {
			res = temp;
			ans += 1;
		}
	}
	cout << ans;
	return 0;
}