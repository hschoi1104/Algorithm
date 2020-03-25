#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(),cout.tie();
using namespace std;
vector<int> a, b;
int n, x, cur[2], maxWin[2], newP;

void go() {
    for (int j = 0; j < 2; j++)
        maxWin[j] = max(maxWin[j], cur[j]);
    return;
}

int main() {
    FIO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        cin >> x;
        b.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        if (!(a[i] == 3 && b[i] == 1) && ((a[i] > b[i]) || (a[i] == 1 && b[i] == 3) || (a[i] == b[i] && newP == 0))) {
            cur[0] += 1;
            go();
            cur[1] = 0;
            newP = 1;
        } else {
            cur[1] += 1;
            go();
            cur[0] = 0;
            newP = 0;
        }
    }
    cout << max(maxWin[0], maxWin[1]);
    return 0;
}

