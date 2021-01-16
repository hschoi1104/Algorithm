//
//  main.cpp
//  boj
//
//  Created by seok on 2020/12/17.
//

#include <iostream>
#include <algorithm>
#define FIO  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main(){
    FIO;
    int t; cin>>t;
    while(t--){
        int a=1000001,b=-1000001,n;
        cin>>n;
        for(int i=0,x;i<n;i++){
            cin>>x;
            a = min(a,x);
            b = max(b,x);
        }
        cout<<a<<" "<<b<<"\n";
    }
    return 0;
}
