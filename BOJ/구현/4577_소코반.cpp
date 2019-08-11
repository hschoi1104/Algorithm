#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> p;
char map[16][16], arr[16][16], dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} }; //.,+,# // b,w,# //u,d,r,l
int n, m, tt = 1, y, x, cnt;
string t, op;
void printmap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char& r = arr[i][j];
			if (map[i][j] == '+') {
				if (r == 'b') cout << 'B';
				else if (r == 'w') cout << 'W';
				else cout << map[i][j];
			}
			else if ((r == 'b' || r == 'w')) cout << r;
			else cout << r;
		}
		cout << "\n";
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (1) {
		cin >> n >> m;
		if (!n && !m) break;
		vector<p> goal;
		bool finish = false;
		for (int i = 0; i < 16; i++) for (int j = 0; j < 16; j++) arr[i][j] = map[i][j] = 0;
		for (int i = 0; i < n; i++) {
			cin >> t;
			for (int j = 0; j < t.length(); j++) {
				char ch = t[j];
				if (ch == 'b' || ch == 'w') {
					arr[i][j] = ch;
					map[i][j] = '.';
				}
				else if (ch == 'B' || ch == 'W') {
					if (ch == 'B') arr[i][j] = 'b';
					else arr[i][j] = 'w';
					map[i][j] = '+';
					goal.push_back({ i,j });
				}
				else if (ch == '#' || ch == '.') {
					arr[i][j] = map[i][j] = ch;
				}
				else if (ch == '+') {
					arr[i][j] = '.';
					map[i][j] = '+';
					goal.push_back({ i,j });
				}
				if (ch == 'w' || ch == 'W')y = i, x = j;
			}
		}
		cin >> op;
		for (auto it : op) {
			if (it == 'U') it = 0;
			else if (it == 'D') it = 1;
			else if (it == 'R') it = 2;
			else it = 3;
			if (arr[y + dir[it][0]][x + dir[it][1]] == '.') {
				arr[y + dir[it][0]][x + dir[it][1]] = 'w';
				arr[y][x] = '.';
				y += dir[it][0];
				x += dir[it][1];
			}
			else if (arr[y + dir[it][0]][x + dir[it][1]] == 'b') {
				if (arr[y + dir[it][0] * 2][x + dir[it][1] * 2] == '.') {
					arr[y + dir[it][0] * 2][x + dir[it][1] * 2] = 'b';
					arr[y + dir[it][0]][x + dir[it][1]] = 'w';
					arr[y][x] = '.';
					y += dir[it][0];
					x += dir[it][1];
				}
			}
			cnt = 0;
			for (auto g : goal) if (arr[g.first][g.second] == 'b') cnt += 1;
			if (goal.size() == cnt) {
				cout << "Game " << tt++ << ": complete\n";
				printmap();
				finish = true;
				break;
			}
		}
		if (finish == true) continue;
		else cout << "Game " << tt++ << ": incomplete\n";
		printmap();
	}
	return 0;
}