#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>arr;
vector<int>v;
vector<int>pre;
vector<int>ans;
int check[100];

int n, m;
bool flag = 0;
bool chk() {
	int num = 0;
	for (int i = 0; i < v.size(); i++) {
		if (i == 0) {
			num = v[i];
			continue;
		}
		num *= 10;
		num += v[i];
	}
	if (find(ans.begin(), ans.end(), num) != ans.end()) return false;
	else {
		ans.push_back(num);
		return true;
	}
}
void go(int cnt) {
	if (cnt == m) {
		if (chk()) {
			for (int p = 0; p < v.size(); p++) {
				printf("%d ", v[p]);
			}
			printf("\n");
		}
	}

	for (int i = 0; i < arr.size(); i++) {
		if (check[i] != 1) {
			v.push_back(arr[i]);
			check[i] = 1;
			go(cnt + 1);
			v.pop_back();
			check[i] = 0;
		}
	}


}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());
	go(0);

	return 0;
}