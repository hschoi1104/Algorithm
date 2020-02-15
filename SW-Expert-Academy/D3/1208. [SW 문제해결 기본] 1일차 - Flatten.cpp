#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int t = 1; t <= 10; t++) {
		multiset<int>s, e;//최소 최대
		int n; cin >> n;
		for (int i = 0; i < 100; i++) {
			int x; cin >> x;
			s.insert(x); e.insert(-x);
		}
		while (n--) {
			if (-*e.begin() - *s.begin() <= 1) break;
			int tmp = *e.begin();
			e.erase(e.begin());
			e.insert(tmp + 1);
			tmp = *s.begin();
			s.erase(s.begin());
			s.insert(tmp + 1);
		}
		cout << "#" << t << " " << -*e.begin() - *s.begin() << "\n";
	}
	return 0;
}

//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	for (int t = 1; t <= 10; t++) {
//		vector<int> v;
//		int n; cin >> n;
//		for (int i = 0; i < 100; i++) {
//			int x; cin >> x;
//			v.push_back(x);
//		}
//		sort(v.begin(), v.end());
//		while (n--) {
//			if (*v.rbegin() - *v.begin() <= 1) break;
//			*v.rbegin() -= 1;
//			*v.begin() += 1;
//			sort(v.begin(), v.end());
//		}
//		cout << "#" << t << " " << *v.rbegin() - *v.begin() << "\n";
//	}
//	return 0;
//}