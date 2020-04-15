#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(a, b) for(int i=a;i<b;i++)
using namespace std;
int n, m;

int main() {
    FIO;
    cin >> n >> m;
    if (n == 1) cout << 1;
    else if (n == 2) cout << min(4, (m - 1) / 2 + 1);
    else {
        if (m >= 7) cout << 5 + (m - 7);
        else cout << min(4, m);
    }
    return 0;
}