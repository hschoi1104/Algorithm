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
int n,t,w,h;
int main(){
    FIO;
    cin>>t;
    while(t--){
        cin>>h>>w>>n;
        int t = n/h+(n%h!=0 ? 1:0);
        cout<<n%h+(n%h == 0 ? h:0)<<(t<10 ? "0":"")<<t<<"\n";
    }
    return 0;
}
