//*g5 & #bfs & !@$me & %ko

#include<bits/stdc++.h>

using namespace std;

int N;

char arr[12][12];

int visited[2][12][12];

int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};

void bfs(int x, int y, int idx, int num) {
	queue<pair<int,int>>q;
	q.push({x,y});
	visited[idx][x][y] = num;
	while (!q.empty()) {
		tie(x,y) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x+xx[i],ty=y+yy[i];
			if (tx < 0 || ty < 0 || tx >= N || ty >= N || visited[idx][tx][ty]) {
				continue;
			}
			if (arr[tx][ty] == '.') {
				visited[idx][tx][ty] = num;
				q.push({tx,ty});
			}
		}
	}
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N ;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	int cnt =0;
	int tmp =1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == '.' && !visited[0][i][j]) {
				bfs(i,j,0,tmp);
				tmp++;
			}
		}
	}

	for (int t = 1; t < tmp; t++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == '.') {
					
					for (int r = 0; r < N; r++) {
						for (int c = 0; c < N; c++) {
							visited[1][r][c] =0;
						}
					}

					arr[i][j] = '@';
					int color = 1;
					for (int r = 0; r < N; r++) {
						for (int c = 0; c < N; c++) {
							if (visited[0][r][c] == t && !visited[1][r][c] && arr[r][c] == '.') {
								bfs(r,c,1,color);
								color++;
							}
						}
					}
					int flag =0;
					for (int r = 0; r < N; r++) {
						for (int c = 0; c < N; c++) {
							if (visited[0][r][c] == t && arr[r][c]=='.') {
								if (visited[1][r][c] != 1) {
									flag=1;
								}
							}
						}
					}
					if (flag) {
						cnt++;

					}
					arr[i][j] = '.';
				}
			}
		}
	}
	cout << cnt <<'\n';
	return 0;
}