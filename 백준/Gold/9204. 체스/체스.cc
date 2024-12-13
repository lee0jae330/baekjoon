#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<utility>
#include<map>
#include<vector>

using namespace std;

int visited[8][8];
queue<pair<int, int>>q;

int xx[4] = { -1,1,1,-1 };
int yy[4] = { 1,1,-1,-1 };

map<pair<int, int>, pair<int, int>>m;

void bfs() {
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		if (visited[x][y] == 4) {
			continue;
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 1;; j++) {
				int tx = x + xx[i] * j;
				int ty = y + yy[i] * j;
				if (tx < 0 || ty < 0 || tx >= 8 || ty >= 8) {
					break;
				}
				if (visited[tx][ty] != -1) {
					continue;
				}
				visited[tx][ty] = visited[x][y] + 1;
				q.push({ tx,ty });
				m[{tx,ty}] = {x,y};
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		for (int i = 0; i < 8; i++) {
			fill(visited[i], visited[i] + 8, -1);
		}
		m.clear();
		char sx, ex;
		int sy, ey;
		cin >> sx >> sy >> ex >> ey;
		visited[sx - 'A'][sy - 1] = 0;
		q.push({ sx - 'A', sy - 1 });

		bfs();

		if (visited[ex - 'A'][ey - 1] == -1) {
			cout << "Impossible" << '\n';
		}
		else {
			cout << visited[ex - 'A'][ey - 1] << ' ';
			vector<pair<int, int>>v;

			int tx = ex -'A', ty = ey - 1;
			
			while (1) {
				v.push_back({tx,ty});

				if (m.find({ tx,ty }) == m.end()) {
					break;
				}
				pair<int,int> value = m[{tx,ty}];
				tx = value.first;
				ty = value.second;
			}
			
			for (int i = v.size() - 1; i >= 0; i--) {
				cout << char(v[i].first +'A') << ' ' << v[i].second +1 <<' ';
			}
			cout <<'\n';
			
		}
	}
}