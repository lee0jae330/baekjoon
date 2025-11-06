#include<bits/stdc++.h>

using namespace std;


char arr[1001][1001];

int fire[1001][1001];
int visited[1001][1001];

int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};

int w, h;

queue<pair<int,int>>q;

void bfs1() {
	while (!q.empty()) {
		auto[x,y] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x+xx[i], ty = y+yy[i];
			if(tx<0||tx>=h||ty<0||ty>=w)
				continue;
			if(fire[tx][ty]!=-1)
				continue;
			if(arr[tx][ty]=='#')
				continue;

			fire[tx][ty] = fire[x][y]+1;
			q.push({tx,ty});
		}
	}
}

void bfs(int x, int y) {
	queue<pair<int,int>>q;
	q.push({x,y});
	visited[x][y]=0;
	while (!q.empty()) {
		tie(x,y) = q.front();
		if (x == 0 || x == h - 1 || y == 0 || y == w - 1) {
			cout << visited[x][y]+1 <<'\n';
			return;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x+xx[i],ty=y+yy[i];
			if(tx<0||tx>=h||ty<0||ty>=w)
				continue;
			if(visited[tx][ty]!=-1)
				continue;
			if (arr[tx][ty] == '.') {
				if (visited[x][y] + 1 < fire[tx][ty]||fire[tx][ty]==-1) {
					visited[tx][ty] = visited[x][y]+1;
					q.push({tx,ty});
				}
			}
		}
	}
	cout << "IMPOSSIBLE" <<'\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			fill(fire[i],fire[i]+w,-1);
			fill(visited[i],visited[i]+w,-1);
		}

		int x, y;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == '*') {
					q.push({i,j});
					fire[i][j] = 0;
				}
				else if (arr[i][j] == '@') {
					x = i, y = j;
				}
			}
		}
		bfs1();
		bfs(x,y);
	}
	return 0;
}