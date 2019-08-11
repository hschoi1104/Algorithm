#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
set <int> s;
int go(int k) {
	k += 1;
	while (k % 10 == 0) {
		k /= 10;
	}
	return k;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, cnt = 0; cin >> n;
	s.insert(n);
	while (1) {
		cnt += 1;
		if (find(s.begin(),s.end(),go(n))==s.end()) {
			n = go(n);
			s.insert(n);
		}
		else break;
	}
	cout << s.size();
	return 0;
}