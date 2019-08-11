#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>v;
bool chk[10];
string s;
int get(int num) {
	if (num > 99999) return  6;
	else if (num > 9999)  return  5;
	else if (num > 999)  return 4;
	else if (num > 99) return  3;
	else if (num > 9) return  2;
	else  return 1;
}
void go(int k) {
	if (s.length() == k) {
		v.push_back(stoi(s));
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (chk[i] != true) {
			s += (i + '0');
			go(k);
			s.pop_back();
		}
	}
}
int main() {
	fill(chk, chk + 10, false);
	int num, t, x;
	cin >> num;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> x;
		chk[x] = true;
	}
	for (int p = 1; p <= 6; p++)	go(p);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()),v.end());
	int index = lower_bound(v.begin(), v.end(), num) - v.begin();
	int ans = 999999999;
	if (v.size() != 0) {
		if (index != v.size() && index != 0) {
			ans = min(abs(num - v[index]) + get(v[index]), abs(num - v[index - 1]) + get(v[index - 1]));
		}
		else if (index == v.size() && index != 0) ans = abs(num-v[index - 1]) + get(v[index - 1]);
		else if (index == 0) ans = abs(num-v[index]) + get(v[index]);
	}
	ans = min(abs(num - 100), ans);
	printf("%d", ans);
	return 0;
}