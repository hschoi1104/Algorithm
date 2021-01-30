//
//  main.cpp
//  boj
//
//  Created by seok on 2021/01/28.
//

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,k,sum,arr[21],dp[21];

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int r=1,l=0;r<=n;r++){
        sum+=arr[r];
        dp[r]=dp[r-1];
        while(sum>=k){
            dp[r]=max(dp[r],dp[l]+sum-k);
            sum-=arr[++l];
        }
    }
    cout<<dp[n]<<"\n";
    
    return 0;
}
