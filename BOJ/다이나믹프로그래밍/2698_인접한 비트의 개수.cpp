//
//  main.cpp
//  boj
//
//  Created by seok on 2021/02/15.
//

#include <bits/stdc++.h>
using namespace std;
int dp[101][101][2],n,k;

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t; cin>>t;
    dp[1][0][0]=dp[1][0][1]=1;
    for(int i=2;i<=100;i++){
        for(int j=0;j<=i;j++){
            dp[i][j][0] = dp[i-1][j][0]+dp[i-1][j][1];
            dp[i][j][1] = dp[i-1][j][0]+(j>0 ?dp[i-1][j-1][1]:0);
        }
    }
    while(t--){
        cin>>n>>k;
        cout<<dp[n][k][0]+dp[n][k][1]<<"\n";
    }
    return 0;
}

