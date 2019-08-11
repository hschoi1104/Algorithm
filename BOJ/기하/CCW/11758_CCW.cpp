#include <stdio.h>
struct Point {
	int y;
	int x;
};
int ccw(Point A, Point B, Point C) {
	int res = (B.x - A.x)*(C.y - A.y) - (C.x - A.x)*(B.y - A.y);
	//�ݽð�
	if (res > 0) return 1;
	//����
	else if (res == 0) return 0;
	//�ð�
	else return -1;
}
int main() {
	Point A, B, C;
	scanf("%d %d", &A.x, &A.y);
	scanf("%d %d", &B.x, &B.y);
	scanf("%d %d", &C.x, &C.y);
	printf("%d",ccw(A, B, C));
	return 0;
}