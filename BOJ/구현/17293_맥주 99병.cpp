#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, t; cin >> n;
	t = n;
	for (int i = t; i > 0; i--) {
		if (i != 1) cout << i << " bottles of beer on the wall, " << i << " bottles of beer.\n";
		else cout << i << " bottle of beer on the wall, " << i << " bottle of beer.\n";
		cout << "Take one down and pass it around, ";


		if (i - 1 > 1) cout << i - 1 << " bottles of beer on the wall.";
		else if (i - 1 == 1) cout << "1 bottle of beer on the wall.";
		else if (i - 1 == 0) cout << "no more bottles of beer on the wall.";
		cout << "\n\n";
	}
	cout << "No more bottles of beer on the wall, no more bottles of beer.\n";
	cout << "Go to the store and buy some more, ";
	if (n > 1)cout << n << " bottles of beer on the wall.";
	else cout << n << " bottle of beer on the wall.";
	return 0;
}