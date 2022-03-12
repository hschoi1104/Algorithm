#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define FIO ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define MAX 100010
typedef long long ll;
using namespace std;
ll n,m,ans,pa[MAX],pay[MAX],led[MAX];
vector<vector<ll>> v;
priority_queue<ll> pq[MAX];

void dfs(ll cur,ll par){
    
    for(auto it: v[cur]){
        dfs(it,cur);
    }
    if(par == -1) return;
    
    ans = max(ans,(ll)pq[cur].size()*led[cur]);
    
    //stl
    if(pq[cur].size() > pq[par].size()) swap(pq[cur],pq[par]);
    
    while(!pq[cur].empty()){
        pq[par].push(pq[cur].top());
        pq[cur].pop();
    }
    
    pay[par]+=pay[cur];
    
    while(pay[par]>m){
        pay[par] -= pq[par].top();
        pq[par].pop();
    }
    
    return;
}
int main(void) {
    FIO;
    cin>>n>>m;
    v.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>pa[i]>>pay[i]>>led[i];
        v[pa[i]].push_back(i);
        pq[i].push(pay[i]);
    }
    dfs(0,-1);
    cout<<ans;
    return 0;
}
