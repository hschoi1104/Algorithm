#include<iostream>
#include <algorithm>
#include <vector>
#include <set>;
using namespace std;
int n, e, k, t, prb = 0;
vector<set<int>>v;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> e;
	v.resize(n + 1);
	for (int i = 0; i < e; i++) {
		vector<int> temp; cin >> k;
		for (int j = 0; j < k; j++) cin >> t, temp.push_back(t);
		sort(temp.begin(), temp.end());
		//선영이가 참가한 경우
		if (temp[0] == 1) {
			prb += 1;
			for (auto it : temp)v[it].insert(prb);
		}
		//선영이가 참가하지 않은경우
		else {
			set<int>f;
			for (auto it : temp) for (auto at : v[it]) f.insert(at);
			for (auto it : temp) v[it] = f;
		}
	}
	for (int i = 0; i < v.size(); i++) if (v[i].size() == prb) cout << i << "\n";
	return 0;
}