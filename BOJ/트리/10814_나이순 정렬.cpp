#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(),cout.tie();
using namespace std;

struct node {
    int a, b;
    string s;

    bool operator<(const node &tmp) const {
        if (a == tmp.a) return b < tmp.b;
        else return a < tmp.a;
    }
};

set<node> se;
int n, m;
string s;

int main() {
    FIO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m >> s;
        se.insert(node{m, i, s});
    }
    for (auto it: se) cout << it.a << " " << it.s << "\n";
    return 0;
}

