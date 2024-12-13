#include<iostream>
#include<queue>
#include<utility>
#include<cstring>
#include<algorithm>

using namespace std;

char arr[201][201];
int visited[201][201];

int xx[4] ={0,1,0};
int yy[4]= {1,0,-1};

int N, M;

queue<pair<int, int>>q;

void bfs() {
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		if (x == N - 1) {
			cout << visited[x][y] <<'\n';
			break;
		}
		for (int i = 0; i < 3; i++) {
			int tx = x + xx[i];
			int ty = y + yy[i];
			if (tx < 0 || ty < 0 || tx >= N || ty >= M || visited[tx][ty] || arr[tx][ty] != 'S') {
				continue;
			}
			q.push({tx,ty});
			visited[tx][ty] =visited[x][y] +1;
			
		}

	}
	while (!q.empty()) {
		q.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (1) {
		memset(visited, 0, sizeof(visited));
		cin >> N >> M;
		if (!N && !M) {
			return 0;
		}
		for (int i = 0; i < N; i++) {
			int black =0;
			for (int j = 0; j < M; j++) {
				cin >> arr[i][j];
				if (!i && arr[i][j] == 'S') {
					q.push({ i,j });
					visited[i][j] = 1;
				}
				if (!black && arr[i][j] == 'B') {
					if (!(i == 0 && j == M - 1 || i == N - 1 && j == M - 1)) {
						arr[i][j] = 'S';
						if (!i) {
							q.push({i,j});
							visited[i][j]=1;
						}
						black =1;
					}
				}
			}
		}

		bfs();
	}
	return 0;
}