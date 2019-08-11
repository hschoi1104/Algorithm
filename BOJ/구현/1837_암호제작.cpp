#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
int arr[1000001];
vector<int>v;
bool go(string st, int t) {
	int temp = 0;
	for (int i = 0; i < st.length(); i++) {

		temp *= 10;
		temp += st[i] - '0';

		if (temp % t == 0) temp = 0;
		else temp -= (temp / t) * t;
	}
	if (temp == 0) return true;
	else return false;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
	int k;
	cin >> s >> k;

	for (int i = 2; i <= sqrt(k); i++) {
		if (arr[i] == 0)
			for (int j = i + i; j <= k; j += i) arr[j] = 1;
	}

	for (int i = 2; i < k; i++) if (arr[i] == 0) v.push_back(i);

	for (auto it : v) {
		if (go(s, it)) {
			cout << "BAD " << it;
			return 0;
		}
	}
	cout << "GOOD";
	return 0;
}