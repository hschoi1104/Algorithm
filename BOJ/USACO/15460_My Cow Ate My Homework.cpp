#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef double d;
int a[100002], b[100002], c[100002];
vector<int>grade;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n; cin >> n;
	for (int i = 1; i <= n; i++)	cin >> a[i];
	c[n] = a[n];
	for (int i = n - 1; i >= 0; i--) c[i] = min(a[i], c[i + 1]);
	b[1] = a[1];
	for (int i = 2; i <= n; i++) b[i] = b[i - 1] + a[i];
	double temp = 0;
	double ans = 0;
	for (int k = 1; k <= n - 2; k++) {
		temp = (d)(b[n] - b[k] - c[k + 1]) / (d)(n - k - 1);
		if (ans == temp) grade.push_back(k);
		else if(ans<temp) {
			grade.clear();
			grade.push_back(k);
			ans = temp;
		}
	}
	for (auto it : grade) cout << it << "\n";
	return 0;
}