#include<bits/stdc++.h>

using namespace std;

int arr[4][4];
int fish_dir[17];
int s_dir, shark;

int xx[8]={-1,-1,0,1,1,1,0,-1};
int yy[8]={0,-1,-1,-1,0,1,1,1};

int sol=0;

void move(){
    for(int i=1;i<=16;i++){
        int flag=0;
        int x,y;
        for(int r=0;r<4;r++){
            for(int c=0;c<4;c++){
                if(arr[r][c]==i){
                    flag=1;    
                    x=r;
                    y=c;
                }
            }
        }
        if(!flag) //해당 물고기 부재시
            continue;
        int cur = fish_dir[i]; //현재 방향
        do{
            int tx=x+xx[cur-1],ty=y+yy[cur-1];
            if(tx<0||ty<0||tx>=4||ty>=4||arr[tx][ty]==-1){
                //이동불가
                cur++;
                if(cur==9)
                    cur=1;
                continue;
            }
            swap(arr[x][y],arr[tx][ty]);
            fish_dir[i]=cur;
            break;
        }while(cur!=fish_dir[i]);
    }
}

void func(){
   /*for(int i=0;i<4;i++){
            for(int j=0;j<4;j++)
                cout << arr[i][j]<<' ';
            cout <<'\n';
        }
    cout <<shark <<'\n';
    cout <<'\n';
    cout <<'\n';*/
    move(); //물고기 이동
    int cp[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            cp[i][j]=arr[i][j];
    }
    int c_dir[17];
    for(int i=0;i<17;i++)
        c_dir[i]=fish_dir[i];
    int cur_shark_dir=s_dir;
    int sx,sy;
    /*for(int i=0;i<4;i++){
            for(int j=0;j<4;j++)
                cout << arr[i][j]<<' ';
            cout <<'\n';
        }
    cout <<shark <<'\n';
    cout <<'\n'; */   
    //상어 위치 찾기
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            if(arr[i][j]==-1){
                sx=i,sy=j;
            }
    }
    //상어의 이동가능 여부
    vector<pair<int,int>>sharkCango;
    for(int i=1;i<=3;i++){
        int tx=sx+xx[s_dir-1]*i,ty=sy+yy[s_dir-1]*i;
        if(tx<0||ty<0||tx>=4||ty>=4)
            break;
        if(!arr[tx][ty])
            continue;
        sharkCango.push_back({tx,ty});
    }
    if(!sharkCango.size()){ //함수 종료 조건
        sol = max(sol,shark);
        //cout <<"---------------end-----------------------"<<"\n\n";
        return;
    }   
    
    for(int i=0;i<sharkCango.size();i++){
        auto [nx,ny] =sharkCango[i];
        int tmp=arr[nx][ny];
        
        arr[sx][sy]=0;
        shark+=arr[nx][ny]; //번호 더하기
        if(arr[nx][ny]) //방향 바꾸기
            s_dir=fish_dir[arr[nx][ny]];
        arr[nx][ny]=-1;
        func();
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++)
                arr[i][j]=cp[i][j];
        }
        for(int i=0;i<17;i++)
            fish_dir[i]=c_dir[i];
        shark-=arr[nx][ny];
        s_dir=cur_shark_dir;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            int num,d;
            cin >> num >> d;
            arr[i][j]=num;
            fish_dir[num]=d;
        }
    }
    /*for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            cout << arr[i][j]<<' ';
        cout <<'\n';
    }
    cout <<'\n';
    for(int i=1;i<=16;i++)
        cout<< fish_dir[i]<<' ';
    cout <<'\n';cout <<'\n';*/
    shark+=arr[0][0];
    s_dir=fish_dir[arr[0][0]];
    arr[0][0]=-1; //상어의 위치는 -1임
    func();
    
    cout << sol<<'\n';
    return 0;
    
}