#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(), cout.tie();
using namespace std;

int arr[501][501], dp[501][501], dir[4][2] = {{0,  1},
                                              {1,  0},
                                              {0,  -1},
                                              {-1, 0}}, n, ans;

int go(int y, int x) {
    int &ret = dp[y][x];
    if (ret != -1) return ret;
    ret = 1;
    int tmp = 0;
    for (int k = 0; k < 4; k++) {
        int ny = y + dir[k][0], nx = x + dir[k][1];
        if (0 <= ny && ny < n && 0 <= nx && nx < n && arr[ny][nx] > arr[y][x]) {
            tmp = max(tmp, go(ny, nx));
        }
    }
    return ret += tmp;
}

int main() {
    FIO;
    cin >> n;
    for (int i = 0; i <= n; i++)memset(dp[i], -1, sizeof(dp[i]));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> arr[i][j];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) go(i, j);
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) ans = max(ans, dp[i][j]);
    cout << ans;
    return 0;
}