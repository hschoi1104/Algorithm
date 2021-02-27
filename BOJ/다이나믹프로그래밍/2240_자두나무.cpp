//
//  main.cpp
//  boj
//
//  Created by seok on 2021/02/15.
//

#include <bits/stdc++.h>
using namespace std;
int t,w,arr[32][1002],n,ans;

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    cin>>t>>w>>n;
    if(n == 1)arr[0][0] = 1;
    else arr[1][0] = 1;
    for(int i = 1; i < t; i++){
        cin>>n;
        arr[0][i] = arr[0][i-1];
        if(n == 1) arr[0][i]+=1;
        for(int j = 1; j <= w; j++){
            arr[j][i] = max(arr[j][i - 1], arr[j-1][i - 1]);
            if(((j % 2) + 1) == n) arr[j][i]++;
        }
    }
    for(int i=0;i<=w;i++) ans = max(ans,arr[i][t-1]);
    cout<<ans;
    return 0;
}

