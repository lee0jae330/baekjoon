#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

char arr[11][11];
int xx[4]={-1,0,1,0};
int yy[4]={0,1,0,-1};

int main(void) {
	fastio();
	int N;
	cin >>N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j]='.';
		}
	}
	string str;
	cin >>str;
	int len= str.length(), x=0,y=0;
	for (int i = 0; i < len; i++) {
		int tx=x, ty=y;
		if (str[i] == 'U'||str[i]=='D') {
			if(str[i]=='U')
				tx+=xx[0], ty+=yy[0];
			else {
				tx+=xx[2],ty+=yy[2];
			}
			if (!(tx >= 0 && ty >= 0 && tx < N && ty < N))
				continue;
			if (arr[x][y] == '.') 
				arr[x][y]='|';
			else if (arr[x][y] == '-') 
				arr[x][y]='+';

			if(arr[tx][ty]=='.')
				arr[tx][ty]='|';
			else if(arr[tx][ty]=='-')
				arr[tx][ty]='+';
		}
		else {
			if(str[i]=='R')
				tx += xx[1], ty += yy[1];
			else
				tx+=xx[3], ty+=yy[3];

			if (!(tx >= 0 && ty >= 0 && tx < N && ty < N))
				continue;

			if(arr[x][y]=='.')
				arr[x][y]='-';
			else if(arr[x][y]=='|')
				arr[x][y]='+';
			
			if(arr[tx][ty]=='.')
				arr[tx][ty]='-';
			else if(arr[tx][ty]=='|')
				arr[tx][ty]='+';
		}
		x=tx, y=ty;
	}
	for (int i = 0; i < N; i++) {
		for(int j=0;j<N;j++)
			cout << arr[i][j];
		cout <<'\n';
	}
	return 0;
}