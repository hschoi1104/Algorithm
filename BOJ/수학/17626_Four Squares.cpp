//
//  main.cpp
//  boj
//
//  Created by seok on 2021/02/15.
//

#include <bits/stdc++.h>
using namespace std;
int ans=5,n;

void go(int num,int last,int dep){
    if(ans<=dep) return;
    if(num == 0){
        if(dep <= 4)ans=min(ans,dep);
        return;
    }
    if(dep == 4){
        if(num == 0)ans=min(ans,dep);
        return;
    }
    for(int k=last;k>=1;k--) if(k*k<=num && num-k*k < k*k) go(num-k*k,k,dep+1);
    return;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    cin>>n;
    for(int k=223;k>=1;k--) if(k*k<=n) go(n-k*k,k,1);
    cout<<ans<<"\n";
    return 0;
}

