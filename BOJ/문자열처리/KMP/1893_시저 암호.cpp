#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
vector<int>pi, ans;
map<char, char>m;
string s, p, a;
void init() {
	pi.clear();
	ans.clear();
	m.clear();
}
void fail() {
	int j = 0;
	for (int i = 1; i < p.size(); i++) {
		while (j > 0 && s[i] != p[j]) j = pi[j - 1];
		if (p[j] == s[i]) {
			pi[i] = j + 1;
			j++;
		}
	}
	return;
}
void kmp(int x) {
	int j = 0,cnt=0;
	for (int i = 0; i < s.size(); i++) {
		while (j > 0 && s[i] != p[j]) j = pi[j - 1];
		if (s[i] == p[j]) {
			if (j == p.size() - 1) {
				cnt++;
				j = pi[j];
			}
			else j++;
		}
	}
	if (cnt == 1) ans.push_back(x);
	return;
}
void makeMap() {
	for (int i = 0; i < a.length()-1; i++) m.insert({ a[i],a[i + 1] });
	m.insert({ a[a.length() - 1],a[0] });
	return;
}
void shift() {
	for (int i = 0; i < p.size(); i++) p[i] = m[p[i]];
	return;
}
void go() {
	for (int i = 0; i < a.size(); i++) {
		kmp(i);
		shift();
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	while (n--) {
		init();
		cin >> a >> p >> s;
		pi.resize(p.size());
		fail();
		makeMap();
		go();
		if (ans.size() == 0) cout << "no solution\n";
		else if (ans.size() == 1) cout << "unique: " << ans[0]<<"\n";
		else {
			cout << "ambiguous:";
			for (int i = 0; i < ans.size(); i++) {
				cout << " "<<ans[i];
			}
			cout << "\n";
		}
	}
	return 0;
}