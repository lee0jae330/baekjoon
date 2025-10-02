#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>

using namespace std;

char arr[101][101];
int visited[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 0; i < 101; i++) {
		fill(visited[i], visited[i] + 101, -1);
	}

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'c') {
				visited[i][j] = 0;
			}
		}
	}
	int cnt = 1;
	while (1) {
		queue<pair<int, int>>q;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 'c') {
					q.emplace(i, j);
				}
			}
		}

		if (q.empty()) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					cout << visited[i][j] << ' ';
				}
				cout << '\n';
			}
			return 0;
		}

		char cp[101][101];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cp[i][j] = arr[i][j];
			}
		}

		while (!q.empty()) {
			auto [x, y] = q.front();
			cp[x][y] = '.';
			q.pop();
			
			int tx = x;
			int ty = y + 1;
			if (ty >= M) {
				continue;
			}

			cp[tx][ty] = 'c';
			if (visited[tx][ty] == -1) {
				visited[tx][ty] = cnt;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				arr[i][j] = cp[i][j];
			}
		}
		
		cnt++;
	}

	
}