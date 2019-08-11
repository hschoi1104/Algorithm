#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int>p;
vector<p>a, b;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int x, n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x != -1) {
			a.push_back({ x,0 });
			b.push_back({ x,0 });
		}
		else {
			a.push_back({ x,-1 });
			b.push_back({ x,-1 });
		}
	}
	bool flag = false;
	//maxinum cow
	for (int i = 0; i < a.size(); i++) {
		if (a[i].first == -1) {
			a[i].first = 0;
			continue;
		}
		else {
			int val = a[i].first;
			int idx = i - 1;
			while (val != 0) {
				if (a[idx].first != --val && a[idx].second == 0) {
					flag = true;
					break;
				}
				a[idx--].first = val;
			}
		}
	}
	if (flag == true) {
		cout << -1;
		return 0;
	}
	int maxV = 0;
	for (int i = 0; i < a.size(); i++) if (a[i].first == 0)maxV += 1;

	//mininum cow
	for (int i = 0; i < b.size(); i++) {
		if (b[i].first == -1) {
			if (i == 0) b[i].first = 0;
			else b[i].first = b[i - 1].first + 1;
		}
		else {
			int val = b[i].first;
			int idx = i - 1;
			while (val != 0) {
				if (b[idx].first != --val && b[idx].second == 0) {
					flag = true;
					break;
				}
				b[idx--].first = val;
			}
		}
	}
	if (flag == true) {
		cout << -1;
		return 0;
	}
	int minV = 0;
	for (int i = 0; i < b.size(); i++) if (b[i].first == 0)minV += 1;
	cout << minV << " " << maxV;
	return 0;
}