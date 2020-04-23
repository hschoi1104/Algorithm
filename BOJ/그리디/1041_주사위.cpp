#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
typedef long long ll;
ll n, arr[7], dir[3][4] = { {4,0,1,5},{0,2,5,3},{1,2,3,4} };
ll getOne() {
	ll tmp = INT_MAX;
	for (int i = 0; i < 6; i++) tmp = min(tmp, arr[i]);
	return tmp;
}
ll getTwo() {
	ll tmp = INT_MAX;
	for (int i = 0; i < 4; i++) {
		tmp = min(tmp, arr[dir[0][i]] + min(arr[2], arr[3]));
		tmp = min(tmp, arr[dir[1][i]] + min(arr[4], arr[1]));
		tmp = min(tmp, arr[dir[2][i]] + min(arr[0], arr[5]));
	}
	return tmp;
}
ll getThree() {
	ll tmp = INT_MAX;
	for (int i = 0; i < 4; i++) {
		if (i == 3) tmp = min(tmp, arr[dir[0][i]] + arr[dir[0][0]]+arr[2]);
		else tmp = min(tmp, arr[dir[0][i]] + arr[dir[0][i + 1]]+arr[2]);
	}

	for (int i = 0; i < 4; i++) {
		if (i == 3) tmp = min(tmp, arr[dir[0][i]] + arr[dir[0][0]] + arr[3]);
		else tmp = min(tmp, arr[dir[0][i]] + arr[dir[0][i + 1]] + arr[3]);
	}
	return tmp;
}
int main() {
	FIO;
	cin >> n;
	for (int i = 0; i < 6; i++)cin >> arr[i];

	if (n == 1) {
		ll mx_val = 0, sum = 0;
		for (int i = 0; i < 7; i++) {
			sum += arr[i];
			mx_val = max(mx_val, arr[i]);
		}
		cout << sum - mx_val;
	}
	else if (n == 2) {
		cout << getTwo() * 4 + getThree() * 4;
	}
	else  cout << getThree() * 4 + ((n - 2) * 4 + (n - 1) * 4) * getTwo() + ((n - 2) * (n - 1) * 4 + (n - 2) * (n - 2)) * getOne();
	return 0;
}