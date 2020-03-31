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
    bool &ret = dp[idx][radi];
    if (ret != false) return;
    ret = true;
    go(idx + 1, (radi + a[idx]) % 360);
    go(idx, (radi + a[idx]) % 360);
    go(idx + 1, (radi - a[idx] + 360) % 360);
}

int main() {
    FIO;
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++) cin>>a[i];
    go(0, 0);
    for (int i = 0; i < m; i++) {
        cin >> x;
        cout<< (ans[x]?"YES\n":"NO\n");
    }
    return 0;
}