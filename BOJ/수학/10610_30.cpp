/*
30����ΰ�? => 3����鼭 10���
3����ΰ�? => ����ڸ��� ���� 3�ǹ��
10����ΰ�? => ���ڸ��� 0
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