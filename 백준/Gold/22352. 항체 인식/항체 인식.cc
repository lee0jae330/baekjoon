#include<bits/stdc++.h>

using namespace std;

int N, M;

int arr[2][31][31];

int visited[2][31][31];
int visited2[2][31][31];

int xx[4] = { 0,1,0,-1 };
int yy[4] = { 1,0,-1,0 };

int bfs(int x, int y, int num) {
	queue<pair<int,int>>q;
	q.push({x,y});
	visited[num][x][y]=1;
	int cnt =0;
	while (!q.empty()) {
		tie(x,y) = q.front();
		cnt++;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x + xx[i] , ty= y+ yy[i];
			if(tx<0||ty<0||tx>=N||ty>=M||visited[num][tx][ty]) {
				continue;
			}
			if (arr[num][tx][ty] == arr[num][x][y]) {
				visited[num][tx][ty] =1;
				q.push({tx,ty});
			}
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[0][i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[1][i][j];
		}
	}

	int num =0;
	set<int>s;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[0][i][j] != arr[1][i][j]) {
				num++;
				s.insert(arr[1][i][j]);
			}
		}
	}

	if (!num) {
		cout << "YES" <<'\n';
		return 0;
	}



	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[0][i][j] && !visited[1][i][j] && (arr[0][i][j] != arr[1][i][j])) {
				if (num == bfs(i, j, 0)&&s.size()==1) {
					cout <<"YES" <<'\n';
					return 0;
				}
				else {
					cout <<"NO" <<'\n';
					return 0;
				}
			}
		}
	}
}