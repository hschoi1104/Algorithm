#include <iostream>
#include <string>
#include <vector>
using namespace std;
string st;
vector<int>v(11);
int main() {
	int n; cin >> n >> st;
	for (int i = 1; i < 10; i++) cin >> v[i];

	bool flag = false;
	for (int i = 0; i < st.length(); i++) {
		if (flag == false) {
			if (st[i] < v[st[i] - '0'] + '0') {
				flag = true;
				st[i] = v[st[i] - '0'] + '0';
			}
			else continue;
		}
		else if (flag == true) {
			if (st[i] <= v[st[i] - '0'] + '0') {
				flag = true;
				st[i] = v[st[i] - '0'] + '0';
			}
			else break;
		}
	}
	cout << st;
	return 0;
}