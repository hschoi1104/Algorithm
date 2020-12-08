//
//  main.cpp
//  boj
//
//  Created by seok on 2020/12/09.
//

#include <iostream>
#include <string>
#define FIO  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;
int n,k,pos=0,x,chk[30];
char arr[30],ah;
bool flag = true;
int main(){
    FIO;
    cin>>n>>k;
    for(int i=0;i<30;i++) arr[i] = '?';
    for(int i=0;i<k;i++){
        cin>>x>>ah;
        pos -= (x%n);
        if(pos<0) pos+=n;
        
        if(arr[pos] == '?'){
            if(chk[ah-'A']){
                cout<<"!";
                return 0;
            }
            arr[pos]=ah;
            chk[ah-'A']=1;
        }
        else{
            if(arr[pos] == ah) continue;
            
            cout<<"!";
            return 0;
        }
    }
    
    int tmp = n;
    while(tmp--){
        if(arr[pos] == '?') cout<<"?";
        else cout<<arr[pos];
        pos++;
        if(pos>=n)pos-=n;
    }
    cout<<"\n";
    return 0;
}
