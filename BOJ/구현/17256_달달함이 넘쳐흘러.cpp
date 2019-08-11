#include <iostream>
using namespace std;
typedef struct node {int x, y, z;};
int main() {
	node A, B, C;
	cin >> A.x >> A.y >> A.z;
	cin >> C.x >> C.y >> C.z;
	cout << C.x - A.z << " " << C.y / A.y << " " << C.z - A.x;
	return 0;
}