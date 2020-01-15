#include <iostream>
using namespace std;
typedef long long ll;
ll arr[10];
void cnt(ll num, int pos) {
	ll sum = 0;
	while (num > 0) {
		sum += (num % 10);
		arr[(num % 10)] += pos;
		num /= 10;
	}
	return;
}
void go(ll num) {
	ll pos = 1;
	while (num > 0) {
		while (num % 10 != 9) {
			cnt(num, pos);
			if (num == 0) break;
			num--;
		}
		if (num % 10 == 9) {
			for (int i = 0; i <= 9; i++) {
				if (i == 0)arr[i] += ((num / 10)) * pos;
				else arr[i] += ((num / 10) + 1) * pos;
			}
		}
		pos *= 10;
		num /= 10;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n; cin >> n;
	go(n);
	for (int i = 0; i <= 9; i++) cout << arr[i] << " ";
	return 0;
}