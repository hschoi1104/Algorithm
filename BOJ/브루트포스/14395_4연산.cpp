#include <iostream>
#include <set>
#include <string>
#include <queue>
using namespace std;
typedef long long ll;
queue<pair<int, string>>q;
set<int>m;
int s, t;

string bfs(ll cur) {
	m.insert(cur);
	q.push({ cur, "" });
	while (!q.empty()) {
		ll num = q.front().first;
		string s = q.front().second;
		if (num == t) return s;
		q.pop();
		if (num*num <= t && m.find(num*num) == m.end()) {
			q.push({ num*num , s + "*" });
			m.insert(num*num);
			if (num*num == t) return s + "*";
		}
		if (num + num <= t && m.find(num+num) == m.end()) {
			q.push({ num + num,s + "+" });
			m.insert(num+num);
			if (num + num == t) return s + "+";
		}
		if (m.find(1) == m.end()) {
			q.push({ 1,s + "/" });
			m.insert(1);
			if (t == 1) return s + "/";
		}
		if (m.find(0) == m.end()) {
			q.push({ 0,s + "-" });
			m.insert(0);
			if (t == 0) return s + "-";
		}
	}
	return "fail";
}
int main() {
	scanf("%d %d", &s, &t);
	if (s == t) {
		cout << "0";
		return 0;
	}
	string res = bfs(s);
	if(res == "fail") cout << "-1";
	else cout << res;
	return 0;
}