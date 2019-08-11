#include <stdio.h>
#include <vector>
#include <set>
using namespace std;
set<int>ans;
vector<int>ff(10);
vector<int>chkff(10);
vector<int>sf(10);
vector<int>chksf(10);
void go(int depth, int gallons) {
	if (depth == 5) {
		ans.insert(gallons);
		return;
	}
	//1->2
	if (depth % 2 == 1) {
		for (int i = 0; i < ff.size(); i++) {
			if (chkff[i] == 0) {
				chkff[i] = 1;
				sf.push_back(ff[i]);
				chksf.push_back(0);
				go(depth + 1, gallons - ff[i]);
				chkff[i] = 0;
				sf.pop_back();
				chksf.pop_back();
			}
		}
	}
	//1<-2
	else {
		for (int i = 0; i < sf.size(); i++) {
			if (chksf[i] == 0) {
				chksf[i] = 1;
				ff.push_back(sf[i]);
				chkff.push_back(0);
				go(depth + 1, gallons + sf[i]);
				chksf[i] = 0;
				ff.pop_back();
				chkff.pop_back();
			}
		}
	}
}
int main() {
	for (int i = 0; i < 10; i++) scanf("%d", &ff[i]);
	for (int i = 0; i < 10; i++) scanf("%d", &sf[i]);
	go(1, 1000);
	printf("%d", ans.size());
	return 0;
}