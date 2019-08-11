#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
vector<p>v;
int n, a, b, ans = 0;
void go(int index, int sum) {
	bool flag = false;
	for (int i = index; i < v.size(); i++) {
		if (v[i].first + i - 1 < n) {
			go(i + v[i].first, sum + v[i].second);
			flag = true;
		}
	}
	if (flag == false) ans = max(ans, sum);
	return;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		v.push_back({ a,b });
	}
	go(0, 0);
	printf("%d", ans);
	return 0;
}