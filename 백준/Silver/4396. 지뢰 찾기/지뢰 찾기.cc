#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

char arr[11][11];
char play[11][11];
char sol[11][11];

int xx[8]={-1,-1,0,1,1,1,0,-1};
int yy[8]={0,1,1,1,0,-1,-1,-1};
int N;

void move() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (play[i][j] == 'x') {
				int x=i, y=j;
				if(arr[x][y]=='.'){//빈칸
					int cnt=0;
					for (int n = 0; n < 8; n++) {
						int tx=x+xx[n],ty=y+yy[n];
						if (tx >= 0 && ty >= 0 && tx < N && ty < N) {
							if(arr[tx][ty]=='*')
								cnt++;
						}
					}
					sol[x][y]='0'+cnt;
				}
				else { //지뢰
					for (int k = 0; k < N; k++) {
						for (int l = 0; l < N; l++) {
							if(arr[k][l]=='*')
								sol[k][l]='*';
						}
					}
				}
			
			}
		}
	}
}

int main(void) {
	fastio();
	cin >>N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >>arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >>play[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for(int j=0;j<N;j++)
			sol[i][j]='.';
	}

	move();

	for (int i = 0; i < N; i++) {
		for(int j=0;j<N;j++)
			cout<<sol[i][j];
		cout<<'\n';
	}
	return 0;
	
}