#include <iostream>
#include <string>
using namespace std;
int arr[1001][1001];
int brr[1000001];
int n, s;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == 'D')arr[i][j + 1] = 1;
			else arr[i][j + 1] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] += arr[i][j - 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[j][i] += arr[j-1][i];
		}
	}
	for (int i = s; i <= n; i++) {
		for (int j = s; j <= n; j++) {
			int temp = arr[i][j] + arr[i - s][j - s] - arr[i - s][j] - arr[i][j - s];
			brr[temp] += 1;
		}
	}
	for (int i = 0; i <= 1000000; i++) {
		if (brr[i] != 0) cout << i << " " << brr[i]<<"\n";
	}
	return 0;
}