 #include <iostream>

#include <string>

#include <vector>

#include <algorithm>

using namespace std;

#define MX 30

class zombie {

public:

  int zx, zy;

  int speed;

  int z_dir;

  int ztype;

  int isInwall = 0;

  int predir = -1;

  int isStop = 0;

public:

  zombie(int zx, int zy, int ztype, char z_dir, int speed) {

    this->zx = zx, this->zy = zy;

    this->ztype = ztype;

    if (z_dir == 'U')

      this->z_dir = 0;

    else if (z_dir == 'R')

      this->z_dir = 1;

    else if (z_dir == 'D')

      this->z_dir = 2;

    else

      this->z_dir = 3;

    this->speed = speed;

  }

};

void fastio() {

  ios_base::sync_with_stdio();

  cin.tie(NULL);

  cout.tie(NULL);

}

int arr[MX][MX];

int wall[MX][MX];

int px, py;

int xx[5] = {-1, 0, 1, 0, 0}; //이동배열

int yy[5] = {0, 1, 0, -1, 0};

string order; //이동명령

int W, Z, D, N, isEnd;

vector<zombie> zv;

int main(void) {

    fastio();

    

    cin >> N >> order;

    cin >> px >> py;

    cin >> W;

    for (int i = 0; i < W; i++) {

        int wx, wy;

        cin >> wx >> wy;

        wall[wx][wy] = 1;

    }

    cin >> Z;

    for (int i = 0; i < Z; i++) {

        int zx, zy, type, speed;

        char zdir;

        cin >> zx >> zy >> type >> zdir >> speed;

        zombie z = zombie(zx, zy, type, zdir, speed);

        zv.push_back(z);

    }

    cin >> D; 

    

  

    for (int d = 1; d <= D; d++) {

   

    int idx = d - 1, pdir, stop=0;

    

    switch (order[idx]) {

    case 'U':

      pdir = 0;

      break;

    case 'R':

      pdir = 1;

      break;

    case 'D':

      pdir = 2;

      break;

    case 'L':

      pdir = 3;

      break;

    default:

      pdir = 4;

    }

    

    int ptx = px + xx[pdir], pty = py + yy[pdir];

    if(wall[ptx][pty]||ptx>N||ptx<1||pty>N||pty<1)

        stop=1;

 

    if(!stop){

        px=ptx, py=pty;

    }

   

 

    //플레이어 이동 끝

    //좀비 이동

    

    for(int j=0;j<Z;j++){

        zombie &z=zv[j];

        int zdir=z.z_dir, zspeed =z.speed;

        int zx=z.zx, zy=z.zy;

        int ztype=z.ztype;

       

       

        if(!ztype){ //하급좀비

            int zStop=0;

            

            for(int s=0;s<zspeed;s++){

                int ztx=zx+xx[zdir], zty=zy+yy[zdir];

                //다음칸에 벽이있는지

                if(wall[ztx][zty]||ztx<1||ztx>N||zty<1||zty>N)

                    zStop=1; //이동불가

                

                if(zStop){//정지

                    if(zdir==0)

                        zdir=2;

                    else if(zdir==1)

                        zdir=3;

                    else if(zdir==2)

                        zdir=0;

                    else

                        zdir=1;

                    break;

                }

                

                //이동

                else{

                     zx=ztx, zy=zty;

                }

           

            }

           

        }

        else{ //상급좀비

                int gap=0,zStop=0;

            if(zdir==0){ //현위치에서 몇칸갈수있는지

                gap=zx-1;

            }

            else if(zdir==1)

                gap=N-zy;

            else if(zdir==2)

                gap=N-zx;

            else

                gap=zy-1;

            if(gap<zspeed){

                zspeed=gap;

            }

            if(!zspeed){

                int nw=0,mw=-1,md,f=0;

                if(zx==1)

                    f=1;

                

                    for(int tx=1;tx<zx;tx++)

                        if(wall[tx][zy])

                            nw++;

                    mw=nw;

                    md=0;

                

                f=0,nw=0;

                if(zy==N)

                    f=1;

                

                    for(int ty=zy+1;ty<=N;ty++)

                        if(wall[zx][ty])

                            nw++;

                    if(mw<nw){

                        mw=nw;

                        md=1;

                    }

                

                f=0,nw=0;

                if(zx==N)

                    f=1;

                

                    for(int tx=zx+1;tx<=N;tx++)

                        if(wall[tx][zy])

                            nw++;

                    if(mw<nw){

                        mw=nw;

                        md=2;

                    }                                

                

                f=0,nw=0;

                if(zy==1)

                    f=1;

               

                    for(int ty=1;ty<zy;ty++)

                        if(wall[zx][ty])

                            nw++;

                    if(mw<nw){

                        mw=nw;

                        md=3;

                    }

               

                zdir=md;

            }

            

            for(int s=0;s<zspeed;s++){

                int ztx=zx+xx[zdir], zty=zy+yy[zdir];

                int zStop=0;

                if(ztx>N||zty>N||ztx<1||zty<1){ //정지 여부 검사

                    zStop=1;

                }

                if(!zStop){ //이동가능하면 다음칸이 벽인지 아닌지 검사

                    if(wall[ztx][zty]){

                            //이동 중이고다음 칸이 벽임     

                            wall[ztx][zty]=0; //벽 삭제

                            zStop=1;

                        }

                    

                }

                if(zStop){ //정지시 다음 이동방향 

                        

                       int nw=0,mw=-1,md,f=0;

                if(zx==1)

                    f=1;

                

                    for(int tx=1;tx<zx;tx++)

                        if(wall[tx][zy])

                            nw++;

                    mw=nw;

                    md=0;

                

                f=0,nw=0;

                if(zy==N)

                    f=1;

                

                    for(int ty=zy+1;ty<=N;ty++)

                        if(wall[zx][ty])

                            nw++;

                    if(mw<nw){

                        mw=nw;

                        md=1;

                    }

                

                f=0,nw=0;

                if(zx==N)

                    f=1;

                

                    for(int tx=zx+1;tx<=N;tx++)

                        if(wall[tx][zy])

                            nw++;

                    if(mw<nw){

                        mw=nw;

                        md=2;

                    }                                

                

                f=0,nw=0;

                if(zy==1)

                    f=1;

               

                    for(int ty=1;ty<zy;ty++)

                        if(wall[zx][ty])

                            nw++;

                    if(mw<nw){

                        mw=nw;

                        md=3;

                    }

                

                zdir=md;

                break;

                    

                }

                else{

                    zx=ztx, zy=zty;

                    if(s==zspeed-1){

                           int nw=0,mw=-1,md,f=0;

                if(zx==1)

                    f=1;

                

                    for(int tx=1;tx<zx;tx++)

                        if(wall[tx][zy])

                            nw++;

                    mw=nw;

                    md=0;

                

                f=0,nw=0;

                if(zy==N)

                    f=1;

                

                    for(int ty=zy+1;ty<=N;ty++)

                        if(wall[zx][ty])

                            nw++;

                    if(mw<nw){

                        mw=nw;

                        md=1;

                    }

                

                f=0,nw=0;

                if(zx==N)

                    f=1;

                

                    for(int tx=zx+1;tx<=N;tx++)

                        if(wall[tx][zy])

                            nw++;

                    if(mw<nw){

                        mw=nw;

                        md=2;

                    }                                

                

                f=0,nw=0;

                if(zy==1)

                    f=1;

                

                    for(int ty=1;ty<zy;ty++)

                        if(wall[zx][ty])

                            nw++;

                    if(mw<nw){

                        mw=nw;

                        md=3;

                    }

                

                zdir=md;

                       

                    

                }

                }

               

            }

            

        }

            z.zx=zx,z.zy=zy;

            z.z_dir=zdir;

            

            

    }

    for(int zidx=0;zidx<zv.size();zidx++){

        if(px==zv[zidx].zx&&py==zv[zidx].zy){

            isEnd=1;

            break;

        }

    }

    if (isEnd) {

      cout << d << '\n';

      cout << "DEAD...";

      break;

    }

  }

  if (!isEnd)

    cout << "ALIVE!";

  return 0;

}

