#include <stdio.h>
#include <vector>
using namespace std;
vector<int>v;
bool arr[400002];
int main() {
	int n, x,cnt=0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		if (v.size() == 0) {
			scanf("%d", &x);
			v.push_back(x);
			continue;
		}
		scanf("%d", &x);
		for (int i = 0; i < v.size(); i++) {
			arr[v[i] + v[v.size() - 1] + 200000] = true;
		}
		for (int i = 0; i < v.size(); i++) {
			if (arr[x - v[i] + 200000] == true) {
				cnt += 1;
				break;
			}
		}
		v.push_back(x);
	}
	printf("%d", cnt);
	return 0;
}