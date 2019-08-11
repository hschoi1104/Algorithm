#include <stdio.h>
#include <utility>
using namespace std;
int arr[102][102];

int main() {
	int n, c,x;
	scanf("%d %d", &n, &c);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= c; j++) {
			scanf("%d", &x);
			arr[i][j] = arr[i][j - 1] + x;
		}
	}
	pair<int, pair<int, int>> pos = { 0,{0,0} };
	for (int i = 1; i <= n - 3; i++) {
		for (int j = 1; j <= c - 3; j++) {
			int sum = 0;
			for(int k=i;k<i+3;k++) 
				sum += arr[k][j + 2] - arr[k][j - 1];
			if (sum > pos.first) pos = { sum,{i,j} };
		}
	}
	printf("%d\n%d %d", pos.first, pos.second.first, pos.second.second);
}