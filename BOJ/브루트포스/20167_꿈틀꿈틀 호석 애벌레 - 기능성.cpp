//
//  main.cpp
//  boj
//
//  Created by seok on 2021/01/28.
//

#include <bits/stdc++.h>
using namespace std;
int n,k,ans,arr[22];

void go(int idx,int sum,int cnt){
    if(idx==n){
        ans = max(ans,cnt);
        return;
    }
    go(idx+1,0,cnt);
    if(sum+arr[idx]>=k) go(idx+1,0,cnt+sum+arr[idx]-k);
    else go(idx+1,sum+arr[idx],cnt);
    return;
}
int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>arr[i];
    go(0,0,0);
    cout<<ans;
    return 0;
}
