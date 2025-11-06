#include<bits/stdc++.h>

using namespace std;

int I;
int visited[301][301];

int xx[8]={-2,-1,1,2,2,1,-1,-2};
int yy[8]={1,2,2,1,-1,-2,-2,-1};

void bfs(int x, int y){
    queue<pair<int,int>>q;
    q.push({x,y});
    visited[x][y]=1;
    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            int tx= x+xx[i],ty=y+yy[i];
            if(tx<0||ty<0||tx>=I||ty>=I)
                continue;
            if(!visited[tx][ty]){
                visited[tx][ty]=visited[x][y]+1;
                q.push({tx,ty});
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        memset(visited,0,sizeof(visited));
        int x,y,dx,dy;
        cin >> I>> x>>y>>dx>>dy;
        bfs(x,y);
        cout << visited[dx][dy]-1<<'\n';
    }
    return 0;
}