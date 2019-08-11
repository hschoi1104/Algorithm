#include <stdio.h>

int main() {
	int x1, y1, x2, y2;
	int x3, y3, x4, y4;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2); //b1
	scanf("%d %d %d %d", &x3, &y3, &x4, &y4); //b2
	//x,y범위를 벗어난경우
	if (y1 >= y4 || y2 <= y3 || x1 >= x4 || x3 >= x2) printf("%d\n", (y2 - y1)*(x2 - x1));
	//y가 포함하는경우(b2가 b1을 y범위 포함)
	else if (y4 >= y2 && y3 <= y1) {
		//오른쪽에걸치게된다면
		if (x1 <= x3 && x3 <= x2 && x2 <= x4) printf("%d\n", (y2 - y1)*(x3 - x1));
		//왼쪽에 걸치게된다면
		else if (x3 <= x1 && x1 <= x4 && x4 <= x2) printf("%d\n", (y2 - y1)*(x2 - x4));
		//걸치지 않는경우 b1의 넓이 만큼의 값출력
		else printf("%d\n", (y2 - y1)*(x2 - x1));
	}
	//x축을 전부 포함해버리는경우
	else if (x3 <= x1 && x2 <= x4) {
		//b2가 아래쪽이라면 
		if (y2 >= y4 && y4 >= y1 && y1 >= y3) printf("%d\n", (y2 - y4)*(x2 - x1));
		//b2가 위쪽이라면
		else if (y4 >= y2 && y2 >= y3 && y3 >= y1) printf("%d\n", (y3 - y1)*(x2 - x1));
		//걸치지 않는경우 b1의 넓이 만큼의 값출력
		else printf("%d\n", (y2 - y1)*(x2 - x1));
	}
	//걸치는경우
	else printf("%d\n", (y2 - y1)*(x2 - x1));
	return 0;
}