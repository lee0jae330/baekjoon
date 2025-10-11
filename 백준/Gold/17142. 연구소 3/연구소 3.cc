#include<bits/stdc++.h>

using namespace std;

int N, M;

int arr[51][51];
int visited[51][51];
int cp[51][51];

int xx[4] = { 0,1,0,-1 };
int yy[4] = { 1,0,-1,0 };

vector<pair<int, int>>virus;

queue<pair<int, int>>q;

void bfs() {
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x + xx[i], ty = y + yy[i];
			if (tx < 0 || ty < 0 || tx >= N || ty >= N||visited[tx][ty]!=-1)
				continue;
			if (arr[tx][ty]==1)
				continue;
			q.push({ tx,ty });
			visited[tx][ty] = visited[x][y] + 1;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	int num = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				virus.push_back({ i,j });
				num++;
				arr[i][j] = 0;
			}
			cp[i][j] = arr[i][j];
		}
	}


	vector<int>comb;
	for (int i = 0; i < M; i++)
		comb.push_back(0);
	for (int i = 0; i < num - M; i++)
		comb.push_back(1);
	int flag = 0,sol=123456789;
	do {
		//arr배열초기화
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				arr[i][j] = cp[i][j];
		}
		//방문 배열 초기화
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				visited[i][j] = -1;
		}
	
		for (int i = 0; i < comb.size(); i++) {
			if (!comb[i]) {
				auto [x, y] = virus[i];
				visited[x][y] = 0;
				q.push(virus[i]);
			}
			else {
				auto [x, y] = virus[i];
				arr[x][y] = 2;
			}
		}
		bfs();

		int f = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!arr[i][j] && visited[i][j] == -1) {
					f = 1;
					break;
				}
			}
		}
		if (f)
			continue;
		int mx = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!arr[i][j]) {
					mx = max(mx, visited[i][j]);
				}
			}
		}
		sol = min(mx, sol);
	} while (next_permutation(comb.begin(), comb.end()));
	if (sol == 123456789)
		cout << -1 << '\n';
	else
		cout << sol << '\n';
	return 0;
}