//
//  main.cpp
//  boj
//
//  Created by seok on 2020/12/04.
//

#include <iostream>
#include <algorithm>
#define FIO  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int w,n,arr[5010],dp[800010];

int main(){
    FIO;
    cin>>w>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int s = arr[i]+arr[j];
            if(w-s<=0) continue;
            else if(dp[w-s] && dp[w-s]<i) {
                cout<<"YES";
                return 0;
            }
            dp[s] = (dp[s] ? min(dp[s],j) : j);
        }
    }
    cout<<"NO";
    return 0;
}
