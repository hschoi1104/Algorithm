//
//  main.cpp
//  boj
//
//  Created by seok on 2020/12/12.
//

#include <iostream>
#include <vector>
#define FIO  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;
int n,m,k,p,arr[41][41],ans;
struct pos{
    int y,x;
};
struct sticker{
    int y,x,cnt;
    vector<pos>v;
};
vector<sticker>stickers;
int main(){
    FIO;
    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
        sticker tmp;
        cin>>tmp.y>>tmp.x;
        for(int i=0;i<tmp.y;i++){
            for(int j=0;j<tmp.x;j++){
                cin>>p;
                if(p) tmp.v.push_back({i,j});
            }
        }
        tmp.cnt=0;
        stickers.push_back(tmp);
    }
    
    for(auto cur: stickers){
        bool flag = false;
        //위치 탐색
        for(int d=0;d<4;d++){
            //회전
            if(d){
                swap(cur.y,cur.x);
                for(int i=0;i<cur.v.size();i++){
                    swap(cur.v[i].y,cur.v[i].x);
                    cur.v[i].x = cur.x-cur.v[i].x-1;
                }
            }

            for(int i=0;i<n-(cur.y-1);i++){
                for(int j=0;j<m-(cur.x-1);j++){
                    //스티커 붙일 수 있는지 확인
                    flag = true;
                    for(auto it:cur.v){
                        if(arr[i+it.y][j+it.x]){
                            flag = false;
                            break;
                        }
                    }
                    //붙일수있다면 붙이고 넘어감
                    if(flag){
                        for(auto it:cur.v) arr[i+it.y][j+it.x]=1;
                        break;
                    }
                }
                if(flag) break;
            }
            //붙였다면 건너뛰기
            if(flag) break;
        }
    }
    
    //남은공간 카운트
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(arr[i][j]) ans+=1;
    cout<<ans<<"\n";
    return 0;
}
