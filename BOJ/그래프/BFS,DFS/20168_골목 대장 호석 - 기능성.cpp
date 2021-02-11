#include <bits/stdc++.h>
using namespace std;

int n,m,a,b,c,ans=INT_MAX,chk[11];
struct node{
    int e,c;
};
vector<vector<node>>v;

void go(int idx,int shame,int remain){
    if(idx == b){
        ans = min(ans,shame);
    };
    for(int i=0;i<v[idx].size();i++){
        node nxt = v[idx][i];
        if(chk[nxt.e] !=0 || remain-nxt.c<0) continue;
        chk[nxt.e]=1;
        go(nxt.e,max(shame,nxt.c),remain-nxt.c);
        chk[nxt.e]=0;
    }
}
int main() {
    ios_base::sync_with_stdio(false),cin.tie(NULL);
    cin>>n>>m>>a>>b>>c;
    v.resize(n+1);
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
