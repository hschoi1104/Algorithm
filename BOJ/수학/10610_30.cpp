/*
30배수인가? => 3배수면서 10배수
3배수인가? => 모든자릿수 합이 3의배수
10배수인가? => 끝자리가 0
*/
#include <iostream>
#include <string>
using namespace std;
int arr[10];
int main() {
	string s;
	cin >> s;
	int sum = 0;
	for (int i = 0; i < s.length(); i++) {
		arr[s[i] - '0']++;
		sum += s[i] - '0';
	}

	if (sum % 3 == 0 && arr[0]) {
		for (int i = 9; i >= 0; i--) {
			while (arr[i]-->0) printf("%d", i);
		}
	}
	else printf("-1\n");
	return 0;
}