#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(),cout.tie();
using namespace std;
int n, a, b, ans, chk[13], arr[30];

void go(int idx) {
    if (idx == 2 * n) {
        ans += 1;
        return;
    }
    if (arr[idx]) go(idx + 1);
    for (int i = 1; i <= n; i++) {
        if (chk[i]) continue;
        if (arr[idx] == 0 && arr[idx + i + 1] == 0) {
            chk[i] = 1;
            arr[idx] = arr[idx + i + 1] = i;
            go(idx + 1);
            chk[i] = 1;
            arr[idx] = arr[idx + i + 1] = 0;
            chk[i] = 0;
        }
    }
    return;
}

int main() {
    FIO;
    cin >> n >> a >> b;
    arr[a - 1] = arr[b - 1] = b - a - 1;
    chk[b - a - 1] = 1;
    go(0);
    cout << ans;
    return 0;
}


