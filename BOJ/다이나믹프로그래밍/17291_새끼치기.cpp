#include <iostream>
using namespace std;
typedef pair<int, int> p;
p arr[30];
int main() {
	int n; cin >> n;
	arr[1] = arr[2] = arr[3] = { 1,0 };//ÇöÀç ¹ú·¹ ¼ö / ±× ³âµµ¿¡ Á×À» ¹ú·¹ ¼ö
	arr[4] = { 1,1 };
	for (int i = 2; i <= n + 1; i++) {
		if (i % 2 == 1) {
			for (int j = i + 1; j <= i + 3 && j <= n + 1; j++) arr[j].first += arr[i].first;
			arr[i + 3].second += arr[i].first;
		}
		else {
			for (int j = i + 1; j <= i + 4 && j <= n + 1; j++) arr[j].first += arr[i].first;
			arr[i + 4].second += arr[i].first;
		}
		arr[i].first = arr[i].first * 2 - arr[i].second;
	}
	cout << arr[n].first;
	return 0;
}