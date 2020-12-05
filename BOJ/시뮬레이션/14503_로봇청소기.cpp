//
//  main.cpp
//  boj
//
//  Created by seok on 2020/12/04.
//

#include <iostream>
#define FIO  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;
int n,m,r,c,d,dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}},arr[51][51],ans=0;
int main(){
    FIO;
    cin>>n>>m>>r>>c>>d;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>arr[i][j];
    
    while(1){
        if(!arr[r][c]) ans+=1;
        arr[r][c]=2;
        
        bool flag = false;
        
        for(int i=0;i<4;i++){
            d += (!d ? 3 : -1);
            int ny = r+dir[d][0],nx = c+dir[d][1];
            
            if(arr[ny][nx] != 1 && arr[ny][nx] ==0){
                r = ny;
                c = nx;
                flag = true;
                break;
            }
        }
        if(flag) continue;
        else{
            int ny = r+dir[(d+2)%4][0], nx = c+dir[(d+2)%4][1];
            if(arr[ny][nx]!=1){
                r = ny;
                c = nx;
            }
            else break;
        }
    }
    cout<<ans;
    return 0;
}
