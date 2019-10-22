#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int>pi;
string pattern;
void fail(){
	int j = 0;
	for (int i = 1; i < pattern.size(); i++){
		while (j > 0 && pattern[i] != pattern[j]) j = pi[j - 1];
		if (pattern[i] == pattern[j]){
			pi[i] = j + 1;
			j++;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (1) {
		getline(cin, pattern);
		if (pattern == ".") break;
		pi.resize(pattern.size());
		fail();
		int len = pattern.size() - pi[pattern.size() - 1];
		if (pattern.size() % len != 0) cout << 1 << "\n";
		else cout << pattern.size() / len << "\n";
		pi.clear();
	}
	return 0;
}
