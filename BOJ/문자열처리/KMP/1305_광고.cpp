#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string pattern;
	int n;
	cin >> n;
	cin.ignore();
	getline(cin, pattern);
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
	printf("%d", n-failure[n-1]);
	return 0;
}
