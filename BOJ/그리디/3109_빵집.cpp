#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(a, b) for(int i=a;i<b;i++)
using namespace std;
int r, c, ans, arr[10010][510], chk[10010][510], dir[3][2] = {{-1, 1},
                                                              {0,  1},
                                                              {1,  1}};
string s;

int dfs(int y, int x) {
    if (x == c - 1) return 1;
    for (int k = 0; k < 3; k++) {
        int ny = y + dir[k][0], nx = x + dir[k][1];
        if (0 <= ny && ny < r && 0 <= nx && nx < c && !arr[ny][nx] && !chk[ny][nx]) {
            chk[ny][nx] = 1;
            if (dfs(ny, nx)) return 1;
        }
    }
    return 0;
}

int main() {
    FIO;
    cin >> r >> c;
    FOR(0, r) {
        cin >> s;
        for (int j = 0; j < s.length(); j++) arr[i][j] = (s[j] == '.' ? 0 : 1);
    }
    FOR(0, r)ans += dfs(i, 0);
    cout << ans;
    return 0;
}