#include <iostream>
#include<queue>
#include<vector>
#include <functional>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
vector<ll> cow, rent;
vector<p> store;
ll arr[100001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m, r, x, y; cin >> n >> m >> r;
	for (int i = 0; i < n; i++) cin >> x, cow.push_back(x);
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		store.push_back({ y,x });
	}
	for (int i = 0; i < r; i++)cin >> x, rent.push_back(x);
	sort(cow.rbegin(), cow.rend());
	sort(store.rbegin(), store.rend());
	sort(rent.begin(), rent.end());
	int cidx = 0, sidx = 0;
	while (1) {
		if (cidx >= n || sidx >= m) break;
		//우유가더 많으면
		if (cow[cidx] > store[sidx].second) {
			arr[cidx] += store[sidx].first * store[sidx].second;
			cow[cidx] -= store[sidx].second;
			store[sidx].second = 0;
		}
		//우유 == 가게 수량
		else if (cow[cidx] == store[sidx].second) {
			arr[cidx] += store[sidx].first * store[sidx].second;
			cow[cidx] = store[sidx].second = 0;
		}
		//가게 수량이 더 많으면
		else {
			arr[cidx] += cow[cidx] * store[sidx].first;
			store[sidx].second -= cow[cidx];
			cow[cidx] = 0;
		}
		if (cow[cidx] == 0) cidx += 1;
		if (store[sidx].second == 0)sidx += 1;
	}
	//소 마리수가 적은것부터 큰 렌트비용과 비교해서 최대이익 업데이트
	int ridx = rent.size() - 1;
	for (int i = cow.size() - 1; i >= 0; i--) {
		if (ridx < 0) break;
		arr[i] = max(arr[i], rent[ridx--]);
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) ans += arr[i];
	cout << ans;
	return 0;
}