//
//  main.cpp
//  boj
//
//  Created by seok on 2021/02/15.
//

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m,arr[310][310],k,a,b,c,d;

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
            arr[i][j]+=(arr[i][j-1]+arr[i-1][j]-arr[i-1][j-1]);
        }
    }
    
    cin>>k;
    while(k--){
        cin>>a>>b>>c>>d;
        cout<<arr[c][d]-arr[c][b-1]-arr[a-1][d]+arr[a-1][b-1]<<"\n";
    }
     return 0;
}

