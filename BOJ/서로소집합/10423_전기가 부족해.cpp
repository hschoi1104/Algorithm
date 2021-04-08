//
//  main.cpp
//  boj
//
//  Created by seok on 2021/02/15.
//

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pa;
struct node{
    int u,v,w;
};
vector<node>edge;
priority_queue<pa,vector<pa>,greater<pa>>pq;
int n,m,k,x,p[1010],u,v,w,fac[1010],chk[1010],ans;
int find(int a){
    if(p[a]==a) return a;
    return p[a]=find(p[a]);
}
void uni(int a,int b,int w){
    a = find(a);
    b = find(b);
    if(a!=b){
        if(fac[a]) p[b]=a,fac[b]=1;
        else if(fac[b])p[a]=b,fac[a]=1;
        else p[b]=a;
        ans+=w;
    }
    return;
}
int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    cin>>n>>m>>k;
    for(int i=0;i<=n;i++) p[i]=i;
    while(k--) cin>>x,fac[x]=chk[x]=1;
    edge.push_back(node{-1,-1,-1});
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        edge.push_back(node{u,v,w});
        pq.push({w,i});
    }
    while(!pq.empty()){
        node cur = edge[pq.top().second];
        pq.pop();
        u = find(cur.u);
        v = find(cur.v);
        if(fac[u] && fac[v]) continue;
        else uni(u,v,cur.w);
    }
    cout<<ans;
    return 0;
}

