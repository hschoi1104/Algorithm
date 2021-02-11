#include <bits/stdc++.h>
using namespace std;

int n,m,a,b,c,ans=INT_MAX,chk[100010],dist[100010];
struct node{int e,c;};
vector<vector<node>>v;

void go(int idx,int s,int r){
    if(idx == b){
        ans = min(ans,s);
        return;
    };
    for(auto nxt : v[idx]){
        if(chk[nxt.e] !=0 || r-nxt.c<0 || dist[nxt.e]<=max(s,nxt.c)) continue;
        dist[nxt.e]=max(s,nxt.c);
        chk[nxt.e]=1;
        go(nxt.e,max(s,nxt.c),r-nxt.c);
        chk[nxt.e]=0;
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(false),cin.tie(NULL);
    cin>>n>>m>>a>>b>>c;
    v.resize(n+1);
    fill(dist,dist+n+5,30);
    for(int i=0;i<m;i++){
        int e,f,g;
        cin>>e>>f>>g;
        v[e].push_back({f,g});
        v[f].push_back({e,g});
    }
    chk[a]=1;
    go(a,-1,c);
    cout<<(ans==INT_MAX?-1:ans)<<"\n";
    return 0;
}
