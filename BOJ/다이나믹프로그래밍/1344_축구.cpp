#include <stdio.h>
#include <algorithm>
using namespace std;

double arr[20][20][20];
int s[12] = { 0,1,4,6,8,9,10,12,14,15,16,18 };
double a, b;
int main() {
	scanf("%lf %lf", &a, &b);
	for (int r = 0; r < 20; r++) {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				arr[r][i][j] = 0.0;
			}
		}
	}
	a /= 100; b /= 100;
	arr[0][0][0] = 1.0;
	for (int r = 0; r <= 17; r++) {
		for (int i = 0; i <= r; i++) {
			for (int j = 0; j <= r; j++) {
				//µÑ´Ù µæÁ¡¸øÇÔ
				arr[r + 1][i][j] += arr[r][i][j] * (1 - a) * (1 - b);
				//aÆÀ¸¸
				arr[r + 1][i + 1][j] += arr[r][i][j] * a * (1 - b);
				//bÆÀ¸¸
				arr[r + 1][i][j + 1] += arr[r][i][j] * (1 - a) * b;
				//a,bÆÀµÑ´Ù
				arr[r + 1][i + 1][j + 1] += arr[r][i][j] * a * b;
			}
		}
	}
	double sum = 1.0;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			sum -= arr[18][s[i]][s[j]];
		}
	}
	printf("%.16lf", sum);
	return 0;
}