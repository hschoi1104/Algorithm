#include <iostream>
#include <string>
using namespace std;

int main() {
	int t, cnt = 1;
	cin >> t;
	cin.ignore();
	while (t--) {
		string s;
		getline(cin, s);
		char gender = s[0];
		int fatherinch, motherinch, temp;
		//아빠가 10미만의 피트입력
		fatherinch = (s[2] - '0') * 12;
		if (s[5] == '"') {
			fatherinch += s[4] - '0';
			motherinch = (s[7] - '0') * 12;
			if (s[10] == '"') motherinch += s[9] - '0';
			else motherinch += (s[9] - '0') * 10 + (s[10] - '0');
		}
		//아빠가 10이상의 피트입력
		else {
			fatherinch += (s[4] - '0') * 10 + (s[5] - '0');
			motherinch = (s[8] - '0') * 12;
			if (s[11] == '"') motherinch += s[10] - '0';
			else motherinch += (s[10] - '0') * 10 + (s[11] - '0');
		}

		//printf(" %c %lf %lf\n", gender, fatherinch, motherinch);
		temp = (motherinch + fatherinch);
		if (gender == 'B') temp += 5;
		else temp -= 5;
		if (temp % 2 == 0) {
			printf("Case #%d: %d'%d\" to %d'%d\"\n", cnt++, (temp / 2 - 4) / 12, (temp / 2 - 4) % 12, (temp / 2 + 4) / 12, (temp / 2 + 4) % 12);
		}
		else {
			printf("Case #%d: %d'%d\" to %d'%d\"\n", cnt++, ((temp + 1) / 2 - 4) / 12, ((temp + 1) / 2 - 4) % 12, ((temp - 1) / 2 + 4) / 12, ((temp - 1) / 2 + 4) % 12);
		}
	}
	return 0;
}