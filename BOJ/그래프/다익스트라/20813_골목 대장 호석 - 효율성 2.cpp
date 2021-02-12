#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<ll,ll>;
ll n,m,a,b,c,k,dist[100010];
struct node{ll e,c;};
vector<vector<node>>v;

bool go(ll mid){
    fill(dist,dist+n+5,1e18);
    priority_queue<p,vector<p>,greater<p>>pq;
    pq.push({0,a});
    dist[a]=0;
    while(!pq.empty()){
        ll cost = pq.top().first, cur = pq.top().second; pq.pop();
        if(dist[cur]<cost) continue;
        for(auto nxt:v[cur]){
            if(nxt.c > mid || dist[nxt.e] <= cost+nxt.c) continue;
            dist[nxt.e]=cost+nxt.c;
            pq.push({dist[nxt.e],nxt.e});
        }
    }
    return dist[b] <= c;
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
    ll l=0,r=1e18;
    while(l+1<r){
        k = (l+r)/2;
        if(go(k)) r = k;
        else l = k;
    }
    
    cout<<(r==1e18?-1:r)<<"\n";
    return 0;
}
