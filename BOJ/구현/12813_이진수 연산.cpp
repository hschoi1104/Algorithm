#include <bits/stdc++.h>
using namespace std;
string a,b;
void bitAnd(){
    for(int i=0;i<a.size();i++) cout<<((a[i] == '1' && b[i] == '1')?"1":"0");
    cout<<"\n";
    return;
}
void bitOr(){
    for(int i=0;i<a.size();i++) cout<<((a[i] == '1' || b[i] == '1')?"1":"0");
    cout<<"\n";
    return;
}
void bitXor(){
    for(int i=0;i<a.size();i++) cout<<(a[i]==b[i]?"0":"1");
    cout<<"\n";
    return;
}
void bitNot(){
    for(auto it:a) cout<<(it=='1'?"0":"1");
    cout<<"\n";
    for(auto it:b) cout<<(it=='1'?"0":"1");
    cout<<"\n";
    return;
}
int main() {
    ios_base::sync_with_stdio(false),cin.tie(NULL);
    cin>>a>>b;
    bitAnd();
    bitOr();
    bitXor();
    bitNot();
    return 0;
}
