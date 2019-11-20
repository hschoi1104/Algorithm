#include <iostream>
#include <string>
using namespace std;
string a, b;
int main() {
	int n; cin >> n;
	cin >> a >> b;
	
	if(n%2 == 1)
		for (int i = 0; i < b.size(); i++) {
			if (b[i] == '1') b[i] = '0';
			else b[i] = '1';
		}
	if (a == b) cout << "Deletion succeeded";
	else cout << "Deletion failed";
	return 0;
}