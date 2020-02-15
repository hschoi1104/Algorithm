#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;
int arr[21][21], ans = INT_MAX, n;
int chk[21];
vector<int>v;
void cal() {
    int tmp = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (!chk[i] && (chk[i] ==  chk[j])) {
                tmp += arr[i][j];
                tmp += arr[j][i];
            }
            else if(chk[i] && (chk[i] == chk[j])) {
                tmp -= arr[i][j];
                tmp -= arr[j][i];
            }
        }
    }
    ans = min(ans, abs(tmp));
    return;
}
void go(int cnt, int pos) {
    if (cnt == 0) {
        cal();
        return;
    }
    for (int i = pos; i <= n; i++) {
        if (!chk[i]) {
            chk[i] = 1;
            go(cnt - 1, i + 1);
            chk[i] = 0;
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> arr[i][j];
    go(n / 2, 1);
    cout << ans;
    return 0;
}