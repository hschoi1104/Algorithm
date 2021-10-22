#include <iostream>
#include <queue>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
struct node{
    int y,x;
};
queue <node> fire, q;
int T,W,H,chk[1010][1010],dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}},ans;
char arr[1010][1010];
void init(int w,int h){
    for(int i=0;i<=h;i++) for(int j=0;j<=w;j++) chk[i][j] = arr[i][j] = 0;
    while(!q.empty()) q.pop();
    while(!fire.empty()) fire.pop();
    ans = 0;
}
bool bfs(){
    while(!q.empty()){
        ans+=1;
        int qs = fire.size();
        while(qs--){
            auto cur = fire.front();
            fire.pop();
            for(int k=0;k<4;k++){
                int ny = cur.y+dir[k][0], nx = cur.x+dir[k][1];
                
                if (nx < 0 || ny < 0 || nx >= W || ny >= H) continue;
                if(arr[ny][nx] == '#' || chk[ny][nx]) continue;
                fire.push({ny,nx});
                chk[ny][nx] = 1;
            }
        }
        //상근이 이동
        qs = q.size();
        while(qs--){
            auto cur = q.front();
            q.pop();
            
            for(int k=0;k<4;k++){
                int ny = cur.y+dir[k][0], nx = cur.x+dir[k][1];
                
                if (nx < 0 || ny < 0 || nx >= W || ny >= H)  return true;
                if(arr[ny][nx] == '#' || chk[ny][nx]) continue;
                q.push({ny,nx});
                chk[ny][nx] = 1;
            }
        }
    }
    return false;
}
int main(){
    FIO;
    cin>>T;
    
    while(T--){
        cin>>W>>H;
        init(W,H);
        for(int i=0;i<H;i++){
            for(int j=0; j<W;j++){
                cin>>arr[i][j];
                if(arr[i][j] == '*') {
                    fire.push({i,j});
                    chk[i][j]=1;
                }
                if(arr[i][j] == '@') {
                    q.push({i,j});
                    chk[i][j]=1;
                }
            }
        }
        bool res = bfs();
        
        if(res == false) cout<<"IMPOSSIBLE";
        else cout<<ans;
        cout<<"\n";
    }
    return 0;
}
