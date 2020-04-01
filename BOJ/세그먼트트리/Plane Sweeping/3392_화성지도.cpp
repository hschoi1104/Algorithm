#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0), cin.tie(), cout.tie();
#define MAX_LEN 65536
using namespace std;

struct node {
    int x, y1, y2, dir;
    bool operator<(const node &tmp) const {
        return x < tmp.x;
    }
};

vector<int> seg, arr;
vector<node> in;
int a, b, c, d, h = 1, n, ans, prv;

void update(int L, int R, int nodeNum, int nodeL, int nodeR, int val) {
    if (L <= nodeL && nodeR <= R) arr[nodeNum] += val;
    else if (nodeR < L || R < nodeL) return;
    else {
        int mid = (nodeL + nodeR) / 2;
        update(L, R, nodeNum * 2, nodeL, mid, val);
        update(L, R, nodeNum * 2 + 1, mid + 1, nodeR, val);
    }
    if (arr[nodeNum]) seg[nodeNum] = nodeR - nodeL + 1;
    else {
        if (nodeL == nodeR) seg[nodeNum] = 0;
        else seg[nodeNum] = seg[nodeNum * 2] + seg[nodeNum * 2 + 1];
    }
}

int main() {
    FIO;
    cin >> n;
    seg.resize(MAX_LEN * 2); arr.resize(MAX_LEN * 2);
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d;
        in.push_back(node{a, b, d, 1});
        in.push_back(node{c, b, d, -1});
    }
    sort(in.begin(), in.end());
    for (int i = 0; i < in.size(); i++) {
        if (i) ans += (in[i].x - prv) * seg[1];
        prv = in[i].x;
        update(in[i].y1, in[i].y2 - 1, 1, 0, 30000, in[i].dir);
    }
    cout << ans;
    return 0;
}