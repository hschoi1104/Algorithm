#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

pair<int, int> arr[1001];
vector<int> v;
int main() {
	int n, k, x;
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= 1000; i++) {
		arr[i].first = 10000;
		arr[i].second = 10000;
	}
	for (int i = 0; i < k; i++) {
		scanf("%d", &x);
		if (v.size() != n) {
			if (find(v.begin(),v.end(),x) != v.end()) {
				arr[x].first += 1;
			}
			else {
				v.push_back(x);
				arr[x] = { 1,i };
			}
		}
		else {
			if (find(v.begin(), v.end(), x) != v.end()) {
				arr[x].first += 1;
				continue;
			}
			pair<int, int> mi = { 10000,10000 };
			int miindex = 0;
			for (int i = 1; i <= 1000; i++) {
				mi = min(arr[i], mi);
				if (mi == arr[i]) miindex = i;
			}
			v.erase(find(v.begin(),v.end(),miindex));
			arr[miindex] = { 10000,10000 };
			v.push_back(x);
			arr[x] = { 1,i };
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}
	return 0;
}