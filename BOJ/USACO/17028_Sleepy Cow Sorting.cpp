#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int>in(n);
	for (int i = 0; i < n; i++)	cin >> in[i];
	for (int i = in.size() - 1; i > 0; i--) {
		if (in[i - 1] > in[i]) {
			cout << i<<"\n";
			return 0;
		}
	}
	cout << 0 << "\n";
	return 0;
} 