//
//  main.cpp
//  boj
//
//  Created by seok on 2021/01/28.
//

#include <bits/stdc++.h>
using namespace std;
int v[11][31];
int n,m,h,a,b,ans =INT_MAX;
bool success=false;
bool chk(){
    for(int i=1;i<=n;i++){
        int idx=i;
        for(int j=1;j<=h;j++) if(v[idx][j]) idx = v[idx][j];
        if(idx!=i) return false;
    }
    return true;
}

void go(int we,int dep){
    if(ans<=dep) return;
    if(chk()){
        success=true;
        ans = min(ans,dep);
    }
    if(dep == 3) return;
    
    for(int i=we;i<n;i++){
        for(int j=1;j<=h;j++){
            if(v[i][j]||v[i+1][j]) continue;
            v[i][j]=i+1;
            v[i+1][j]=i;
            go(i,dep+1);
            v[i][j]=v[i+1][j]=0;
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    cin>>n>>m>>h;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        v[b][a]=b+1;
        v[b+1][a]=b;
    }
    go(1,0);
    cout<<((ans >3|| !success)?-1:ans)<<"\n";
    return 0;
}
