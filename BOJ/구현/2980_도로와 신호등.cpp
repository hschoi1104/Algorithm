#include <stdio.h>
#include <vector>
using namespace std;
vector<pair<int, pair<int, int>>>v;
int main() {
	int n, l;
	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v.push_back({ a,{b,c} });
	}
	int prev = 0;
	int time = 0;
	for (int i = 0; i < v.size(); i++) {
		time += v[i].first - prev;
		prev = v[i].first;
		if (time % (v[i].second.first + v[i].second.second) < v[i].second.first) {
			time += v[i].second.first - (time % (v[i].second.first + v[i].second.second));
		}
	}
	time += l - v[v.size() - 1].first;
	printf("%d", time);
	return 0;
}
