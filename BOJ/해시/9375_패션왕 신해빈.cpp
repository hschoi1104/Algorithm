#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		unordered_map<string, int>um;
		int n;
		cin >> n;
		string type; string s;
		for (int i = 0; i < n; i++) {
			cin >> s >> type;
			if (um[type] == 0) {
				um[type] += 1;
			}
			else um[type] += 1;
		}
		int sum = 1;
		for (auto it = um.begin(); it != um.end(); it++) {
			sum *= (it->second+1);
		}
		printf("%d\n", sum - 1);
	}
	return 0;
}