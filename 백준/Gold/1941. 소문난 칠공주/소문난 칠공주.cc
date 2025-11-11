#include<bits/stdc++.h>

using namespace std;

char arr[5][5];
int visited[5][5];

int xx[4] = { 0,1,0,-1 };
int yy[4] = { 1,0,-1,0 };

int sol;

bool bfs(int x, int y) {
	queue<pair<int, int>>q;
	q.emplace(x, y);
	visited[x][y] = 1;
	int cnt = 0;
	int total = 0;
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		if (arr[x][y] == 'S') {
			cnt++;
		}
		total++;

		for (int i = 0; i < 4; i++) {
			int tx = x + xx[i], ty = y + yy[i];
			if (tx < 0 || ty < 0 || tx >= 5 || ty >= 5 || visited[tx][ty]) {
				continue;
			}
			visited[tx][ty] = 1;
			q.emplace(tx, ty);
		}
	}
	
	return cnt >= 4 && total == 7;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}

	vector<int>comb(7, 0);
	for (int i = 0; i < 25 - 7; i++) {
		comb.push_back(1);
	}

	do {
		for (int i = 0; i < 5; i++) {
			fill(visited[i], visited[i] + 5, 1);
		}
		int flag =0;
		int sx, sy;
		for (int i = 0; i < 25; i++) {
			if (!comb[i]) {
				visited[i/5][i%5] = 0;
				if (!flag) {
					sx = i/5;
					sy = i%5;
				}
			}
		}
		if (bfs(sx, sy)) {
			sol++;
		}

	} while (next_permutation(comb.begin(), comb.end()));

	cout << sol << '\n';
	return 0;
}