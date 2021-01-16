//
//  main.cpp
//  boj
//
//  Created by seok on 2021/01/16.
//

#include <iostream>
#include <string>
using namespace std;
string a,b;
int t,ans,i,j;
int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    cin>>t;
    while(t--){
        cin>>a>>b;
        i=j=ans=0;
        while(i<a.size()){
            while(i<a.size() && a[i] == 'a') i++;
            while(j<a.size() && b[j] == 'a') j++;
            ans+=abs(j-i);
            i+=1;
            j+=1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
