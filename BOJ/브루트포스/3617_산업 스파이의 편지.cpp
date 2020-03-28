#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(),cout.tie();
using namespace std;
int t;
bool sosu[10000000], chk[8];
string s;
set<int> se;

void init() {
    sosu[0] = sosu[1] = true;
    for (int i = 2; i * i <= 10000000; i++) {
        if (sosu[i]) continue;
        for (int j = i + i; j <= 10000000; j += i) {
            sosu[j] = true;
        }
    }
}

void go(int idx,int res) {
    if (idx == s.length()) return;

    for (int i = 0; i < s.length(); i++) {
        if (chk[i]) continue;
        chk[i] = true;

        if (!sosu[res*10+s[i]-'0'])se.insert(res*10+s[i]-'0');
        go(idx + 1,res*10+s[i]-'0');

        chk[i] = false;
    }
    return;
}

int main() {
    FIO;
    init();
    cin >> t;
    while (t--) {
        memset(chk, 0, sizeof(chk));
        cin >> s;
        go(0,0);
        cout << se.size() << "\n";
        se.clear();
    }
    return 0;
}