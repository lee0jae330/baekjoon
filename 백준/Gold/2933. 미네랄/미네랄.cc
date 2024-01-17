#include<bits/stdc++.h>

using namespace std;

int R, C;

char arr[101][101];

int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};

int visited[101][101];

void bfs(int x, int y, int num) {
	queue<pair<int,int>>q;
	q.push({ x,y });
	visited[x][y]=num;
	while (!q.empty()) {
		tie(x,y) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x+xx[i], ty= y+yy[i];
			if(tx<0||tx>=R||ty<0||ty>=C)
				continue;
			if(visited[tx][ty])
				continue;
			if (arr[tx][ty] == 'x') {
				visited[tx][ty] = num;
				q.push({tx,ty});
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
		}
	}
	int N;
	cin >> N;
	for (int repeat = 0; repeat < N; repeat++) {
		
		memset(visited,0,sizeof(visited));

		int h;
		cin >> h;
		if (repeat % 2) { // 오른쪽 -> 왼쪽
			for (int i = C - 1; i >= 0; i--) {
				if (arr[R - h][i] == 'x') {
					arr[R - h][i] = '.';
					break;
				}
			}
		}
		else { //왼쪽 -> 오른쪽
			for (int i = 0; i < C; i++) {
				if (arr[R - h][i] == 'x') {
					arr[R - h][i] = '.';
					break;
				}
			}
		}

		int cnt = 1;


		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (arr[i][j] == 'x' && !visited[i][j]) {
					bfs(i,j,cnt);
					cnt++;
				}
			}
		}

		if (cnt > 1) { //1보다 크면 클러스터가 2개 이상
			for (int num = 1; num < cnt; num++) {
				int dist = 101;
				for (int c = 0; c < C; c++) {
					for (int r = R - 1; r >= 0; r--) {
						if (visited[r][c] == num) {
							int tmp =0;
							for (int i = r + 1; i < R; i++) {
								if (!visited[i][c]) {
									tmp++;
								}
								else {
									break;
								}
							}
							dist = min(dist, tmp);
							break;
						}
					}
				}
				if(!dist)
					continue;
				for (int c = 0; c < C; c++) {
					for (int r = R - 1; r >= 0; r--) {
						if (visited[r][c] == num) {
							swap(arr[r][c], arr[r+dist][c]);
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
	return 0;
}