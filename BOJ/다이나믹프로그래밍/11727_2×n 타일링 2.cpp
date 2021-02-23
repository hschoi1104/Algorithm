//
//  main.cpp
//  boj
//
//  Created by seok on 2021/02/15.
//

#include <bits/stdc++.h>
using namespace std;
int n,dp[1010],MOD=10007;
int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    cin>>n;
    dp[1]=1;
    dp[2]=3;
    for(int i=3;i<=n;i++) dp[i] = (dp[i-1]+2*dp[i-2])%MOD;
    cout<<dp[n];
    return 0;
}

