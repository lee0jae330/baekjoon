#include<bits/stdc++.h>

using namespace std;

const int MX = 101;

int N,M,H;
int arr[MX][MX][MX];
int dist[MX][MX][MX];

int zz[2]={1,-1};
int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};
queue<tuple<int,int,int>>q;

void bfs(){
    while(!q.empty()){
        int z = get<0>(q.front());
        int x = get<1>(q.front());
        int y = get<2>(q.front());
        q.pop();
        for(int i=0;i<2;i++){
            int tz = z+zz[i];
            if(tz<0||tz>=H)
                continue;
            if(!arr[tz][x][y]&&dist[tz][x][y]==-1){
                dist[tz][x][y]=dist[z][x][y]+1;
                q.push({tz,x,y});
            }
        }
        for(int i=0;i<4;i++){
            int tx= x+xx[i],ty= y+yy[i];
            if(tx<0||ty<0||tx>=N||ty>=M)
                continue;
            if(!arr[z][tx][ty]&&dist[z][tx][ty]==-1){
                dist[z][tx][ty]=dist[z][x][y]+1;
                q.push({z,tx,ty});
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> M >> N >>H;
 
    
    for(int i=0;i<H;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<M;k++){
                cin >> arr[i][j][k];
                dist[i][j][k]=-1;
                if(arr[i][j][k]==1){
                    q.push({i,j,k});
                    dist[i][j][k]=0;
                }
            }
        }
    }
    bfs();
    int sol =0;
    for(int i=0;i<H;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<M;k++){
                if(!arr[i][j][k]){
                    if(dist[i][j][k]==-1){
                        cout << -1<<'\n';
                        return 0;
                    }
                    else{
                        sol=max(sol,dist[i][j][k]);
                    }
                }
            }
        }
    }
    cout << sol<<'\n';
    return 0;
    
}