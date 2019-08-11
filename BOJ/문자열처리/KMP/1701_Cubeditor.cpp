#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string pattern;
	getline(cin, pattern);
	string temp;
	int ans = 0;
	//Failure function
	for (int k = 0; k < pattern.length()-1; k++) {
		string temp = pattern.substr(k);
		vector<int>failure(temp.length(), 0);
		int j = 0;
		for (int i = 1; i < temp.size(); i++) {
			while (j > 0 && temp[i] != temp[j]) j = failure[j - 1];
			if (temp[i] == temp[j]) {
				failure[i] = j + 1;
				ans = max(ans, j + 1);
				j++;
			}
		}
		failure.clear();
	}
	printf("%d", ans);
	return 0;
}
