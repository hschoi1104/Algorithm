//
//  main.cpp
//  boj
//
//  Created by seok on 2021/03/11.
//

#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int n,stNum;
string st;
struct node{
    int val;
    string binary;
};
vector<node>v;
int binaryTodecimal(string str){
    int res = 0;
    for(int i=str.length()-1;i>=0;i--){
        if(str[i]=='1') res+= pow(2,str.length()-1-i);
    }
    return res;
}
string decimalTobinary(int num){
    string res="";
    while(num>1){
        if(num%2) res+="1";
        else res+="0";
        num/=2;
    }
    if(num==1) res+="1";
    reverse(res.begin(),res.end());
    return res;
}
int main(){
    FIO;
    cin>>n>>st;
    stNum = binaryTodecimal(st);
    for(int i=0;i<pow(2,n)/2;i++){
        int tmp = i^(i>>1);
        v.push_back(node{tmp^stNum,decimalTobinary(tmp^stNum)});
        v.push_back(node{((int)(pow(2,n)-1)-tmp)^stNum,decimalTobinary(((int)(pow(2,n)-1)-tmp)^stNum)});
    }
    for(auto it:v) {
        for(int i=0;i<n-it.binary.length();i++) cout<<"0";
        cout<<it.binary<<"\n";
    }
    return 0;
}

