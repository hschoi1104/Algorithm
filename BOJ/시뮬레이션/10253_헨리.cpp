//
//  main.cpp
//  boj
//
//  Created by seok on 2020/12/14.
//

#include <iostream>
#define FIO  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;
typedef long long ll;
ll t,a,b;
ll gcd(ll a,ll b){ return b ? gcd(b,a%b):a;}

int main(){
    FIO;
    cin>>t;
    while(t--){
        cin>>a>>b;
        while(a!=1){
            ll tmp = (b%a!=0) ? b/a+1:b/a;
            a = a*tmp-b; b *= tmp;
            ll res = gcd(a,b); a/=res; b/=res;
        }
        cout<<b<<"\n";
    }
    return 0;
}
