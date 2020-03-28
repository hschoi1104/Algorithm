#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(),cout.tie();
using namespace std;
int n, m, x;
vector<int> a;
bool dp[13][361];
bool ans[361];

void go(int idx, int radi) {
    ans[radi] = true;
    if (idx == n) return;
    int &ret = dp[idx][radi];
    if (ret != -1) return;
    ret = 1;
    go(idx + 1, (radi + a[idx]) % 360);
    go(idx, (radi + a[idx]) % 360);
    go(idx + 1, (radi - a[idx] + 360) % 360);
}

int main() {
    FIO;
    memset(dp, 0, sizeof(dp));
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    go(0, 0);
    for (int i = 0; i < m; i++) {
        cin >> x;
        if (ans[x]) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}