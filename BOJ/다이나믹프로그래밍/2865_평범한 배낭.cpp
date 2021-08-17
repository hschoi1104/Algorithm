//
//  main.cpp
//  boj
//
//  Created by seok on 2021/08/17.
//

//dp[i][j] = j크기의 가방에 i번째 물건까지 넣었을때의 최대 가치
//dp[i][j] = max(dp[i-1][j],dp[i][j-w[i]]+v[i])
#include <iostream>
#include <vector>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int dp[110][100010],n,k,w[110],v[110];
int main(){
    FIO;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(j>=w[i]){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[n][k]<<"\n";
    return 0;
}
