#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	while (1) {
		string pattern;
		getline(cin, pattern);
		if (pattern == ".") break;
		vector<int>failure(pattern.length(), 0);
		//Failure function
		int j = 0;
		for (int i = 1; i < pattern.size(); i++) {
			while (j > 0 && pattern[i] != pattern[j]) j = failure[j - 1];
			if (pattern[i] == pattern[j]) {
				failure[i] = j + 1;
				j++;
			}
		}
		int len = pattern.size() - failure[pattern.size() - 1];
		if (pattern.size() % len != 0) printf("1\n");
		else printf("%d\n", pattern.size() / len);
	}
	return 0;
}
