#include<bits/stdc++.h>

using namespace std;

int R,C;
int solx,soly;

char arr[1001][1001];
int visited[1001][1001];

int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};

queue<pair<int,int>>q;

void bfs() {
	while(!q.empty()) {
		auto[x,y] = q.front();
		q.pop();
		for(int i=0;i<4;i++) {
			int tx = x+xx[i];
			int ty = y+yy[i];
			if(tx<0||ty<0|| tx>=R ||ty >=C || visited[tx][ty]!=-1||arr[tx][ty] =='#') {
				continue;
			}
			visited[tx][ty] = visited[x][y]+1;
			q.push({tx,ty});
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int fx, fy;
	memset(visited,-1,sizeof(visited));	
	cin >> R >> C;
	for(int i=0 ;i<R ;i++) {
		for(int j=0;j<C;j++) {
			cin >> arr[i][j];
			if(arr[i][j]=='&')
				solx=i,soly=j;
			if(arr[i][j]=='@') {
				q.push({i,j});
				visited[i][j]=0;
			}
		}
	}
	bfs();
	if(visited[solx][soly]!=-1) {
		visited[solx][soly]--;
	}
	cout << visited[solx][soly] <<'\n';
	return 0;

}