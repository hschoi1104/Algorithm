#include <iostream>
#include <string>
using namespace std;
int arr[27] = { 1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4 };
int point[27] = { 2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9 };
int key[10];
int main() {
	int p;
	string s,ans;
	for (int i = 1; i <= 9; i++) {
		scanf("%d", &p);
		key[p] = i;
	}
	cin.ignore();
	getline(cin, s);
	int prevpoint = -1;
	for (int i = 0; i < s.length(); i++) {
		int curpoint = point[s[i] - 97];
		if (prevpoint == curpoint) ans+='#';
		else prevpoint = curpoint;
		for (int j = 0; j < arr[s[i] - 97]; j++) ans += key[point[s[i] - 97]] + '0';
	}
	cout << ans;
	return 0;
}