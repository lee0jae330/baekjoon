#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cstdlib>
#include<memory.h>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[21][21];
int cp[21][21];
int WALL[21][21];
int visited[21][21];

vector<pair<int, int>>toSearch;
vector<pair<pair<int, int>, int>> heater;
int R, C, K, W;

class wall {
public:
	int x, y;
	int up = 0, down = 0, left = 0, right = 0;
public:
	wall() {

	}

	wall(int x, int y) {
		this->x = x, this->y;

	}
};

map<pair<int, int>, wall>m;

void arrTocp() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			cp[i][j] = arr[i][j];
	}
}


void cpToarr() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			arr[i][j] = cp[i][j];
	}
}

int iswindBlow = 0;

void windBlow(int x, int y, int dir) {
	queue<pair<pair<int, int>, int>>q;
	memset(visited, 0, sizeof(visited));
	int temp = 5;
	if (dir == 1) { //오른쪽
		if (!iswindBlow) { //처음
			if (y + 1 < C) {
				arr[x][y + 1] = temp;
				q.push({ {x,y + 1},temp - 1 });
				visited[x][y + 1];
				while (!q.empty()) {
					x = q.front().first.first;
					y = q.front().first.second;
					int t = q.front().second;
					q.pop();
					if (t == 0)
						continue;
					int u = 0, d = 0, r = 0, tx, ty;
					if (WALL[x][y]) { //x,y에 벽이 있다면
						wall tmp = m[{x, y}];
						if (tmp.up)
							u = 1;
						if (tmp.down)
							d = 1;
						if (tmp.right)
							r = 1;
					}

					if (!u) {
						tx = x - 1, ty = y;
						if (tx >= 0) { // (x,y) -> (x-1, y+1)
							int flag = 0;
							if (WALL[tx][ty]) {
								wall tmp = m[{tx, ty}];
								if (tmp.right) {
									flag = 1;
								}
							}
							if (!flag) {
								ty++;
								if (ty < C&&!visited[tx][ty]) {
									arr[tx][ty] = t;
									visited[tx][ty] = 1;
									q.push({ {tx,ty},t - 1 });
								}
							}
						}
					}

					if (!r) { //(x,y) -> (x,y+1)
						tx = x, ty = y + 1;
						if (ty < C&&!visited[tx][ty]) {
							arr[tx][ty] = t;
							visited[tx][ty] = 1;
							q.push({ {tx,ty},t - 1 });
						}
					}

					if (!d) { //(x,y)->(x+1,y+1)
						tx = x + 1, ty = y;
						if (tx < R) {
							int flag = 0;
							if (WALL[tx][ty]) {
								wall tmp = m[{tx, ty}];
								if (tmp.right) {
									flag = 1;
								}
							}

							if (!flag) {
								ty++;
								if (ty < C&&!visited[tx][ty]) {
									arr[tx][ty] = t;
									visited[tx][ty] = 1;

									q.push({ {tx,ty},t - 1 });
								}
							}
						}
					}

				}
			}
			else {
				return;
			}
		}
		else {
			if (y + 1 < C) {
				arr[x][y + 1] += temp;
				q.push({ {x,y + 1},temp - 1 });
				visited[x][y + 1] = 1;
				while (!q.empty()) {
					x = q.front().first.first;
					y = q.front().first.second;
					int t = q.front().second;
					q.pop();
					if (t == 0)
						continue;
					int u = 0, d = 0, r = 0, tx, ty;
					if (WALL[x][y]) { //x,y에 벽이 있다면
						wall tmp = m[{x, y}];
						if (tmp.up)
							u = 1;
						if (tmp.down)
							d = 1;
						if (tmp.right)
							r = 1;
					}

					if (!u) {
						tx = x - 1, ty = y;
						if (tx >= 0) { // (x,y) -> (x-1, y+1)
							int flag = 0;
							if (WALL[tx][ty]) {
								wall tmp = m[{tx, ty}];
								if (tmp.right) {
									flag = 1;
								}
							}
							if (!flag) {
								ty++;
								if (ty < C&&!visited[tx][ty]) {
									arr[tx][ty] += t;
									visited[tx][ty] = 1;

									q.push({ {tx,ty},t - 1 });
								}
							}
						}
					}

					if (!r) { //(x,y) -> (x,y+1)
						tx = x, ty = y + 1;
						if (ty < C&&!visited[tx][ty]) {
							arr[tx][ty] += t;
							visited[tx][ty] = 1;
							q.push({ {tx,ty},t - 1 });
						}
					}

					if (!d) { //(x,y)->(x+1,y+1)
						tx = x + 1, ty = y;
						if (tx < R) {
							int flag = 0;
							if (WALL[tx][ty]) {
								wall tmp = m[{tx, ty}];
								if (tmp.right) {
									flag = 1;
								}
							}

							if (!flag) {
								ty++;
								if (ty < C&&!visited[tx][ty]) {
									visited[tx][ty] = 1;
									arr[tx][ty] += t;
									q.push({ {tx,ty},t - 1 });
								}
							}
						}
					}

				}
			}
			else {
				return;
			}
		}
	}
	else if (dir == 2) {//왼쪽
		if (!iswindBlow) { //처음
			if (y - 1 >= 0) {
				arr[x][y - 1] = temp;
				q.push({ {x,y - 1},temp - 1 });
				visited[x][y - 1] = 1;
				while (!q.empty()) {
					x = q.front().first.first;
					y = q.front().first.second;
					int t = q.front().second;
					q.pop();
					if (t == 0)
						continue;
					int u = 0, d = 0, l = 0, tx, ty;
					if (WALL[x][y]) { //x,y에 벽이 있다면
						wall tmp = m[{x, y}];
						if (tmp.up)
							u = 1;
						if (tmp.down)
							d = 1;
						if (tmp.left)
							l = 1;
					}

					if (!u) {
						tx = x - 1, ty = y;
						if (tx >= 0) { // (x,y) -> (x-1, y+1)
							int flag = 0;
							if (WALL[tx][ty]) {
								wall tmp = m[{tx, ty}];
								if (tmp.left) {
									flag = 1;
								}
							}
							if (!flag) {
								ty--;
								if (ty >= 0&&!visited[tx][ty]) {
									arr[tx][ty] = t;
									visited[tx][ty] = 1;
									q.push({ {tx,ty},t - 1 });
								}
							}
						}
					}

					if (!l) { //(x,y) -> (x,y+1)
						tx = x, ty = y - 1;
						if (ty >= 0&&!visited[tx][ty]) {
							arr[tx][ty] = t;
							visited[tx][ty] = 1;
							q.push({ {tx,ty},t - 1 });
						}
					}

					if (!d) { //(x,y)->(x+1,y+1)
						tx = x + 1, ty = y;
						if (tx < R) {
							int flag = 0;
							if (WALL[tx][ty]) {
								wall tmp = m[{tx, ty}];
								if (tmp.left) {
									flag = 1;
								}
							}

							if (!flag) {
								ty--;
								if (ty >= 0&&!visited[tx][ty]) {
									visited[tx][ty] = 1;
									arr[tx][ty] = t;
									q.push({ {tx,ty},t - 1 });
								}
							}
						}
					}

				}
			}
			else {
				return;
			}
		}
		else { //처음 아님
			if (y - 1 >= 0) {
				arr[x][y - 1] += temp;
				q.push({ {x,y - 1},temp - 1 });
				visited[x][y - 1] = 1;
				while (!q.empty()) {
					x = q.front().first.first;
					y = q.front().first.second;
					int t = q.front().second;
					q.pop();
					if (t == 0)
						continue;
					int u = 0, d = 0, l = 0, tx, ty;
					if (WALL[x][y]) { //x,y에 벽이 있다면
						wall tmp = m[{x, y}];
						if (tmp.up)
							u = 1;
						if (tmp.down)
							d = 1;
						if (tmp.left)
							l = 1;
					}

					if (!u) {
						tx = x - 1, ty = y;
						if (tx >= 0) { // (x,y) -> (x-1, y-1)
							int flag = 0;
							if (WALL[tx][ty]) {
								wall tmp = m[{tx, ty}];
								if (tmp.left) {
									flag = 1;
								}
							}
							if (!flag) {
								ty--;
								if (ty >= 0&&!visited[tx][ty]) {
									arr[tx][ty] += t;
									visited[tx][ty] = 1;
									q.push({ {tx,ty},t - 1 });
								}
							}
						}
					}

					if (!l) { //(x,y) -> (x,y-1)
						tx = x, ty = y - 1;
						if (ty >= 0&&!visited[tx][ty]) {
							arr[tx][ty] += t;
							visited[tx][ty] = 1;
							q.push({ {tx,ty},t - 1 });
						}
					}

					if (!d) { //(x,y)->(x+1,y-1)
						tx = x + 1, ty = y;
						if (tx < R) {
							int flag = 0;
							if (WALL[tx][ty]) {
								wall tmp = m[{tx, ty}];
								if (tmp.left) {
									flag = 1;
								}
							}

							if (!flag) {
								ty--;
								if (ty >= 0&&!visited[tx][ty]) {
									arr[tx][ty] += t;
									visited[tx][ty] = 1;
									q.push({ {tx,ty},t - 1 });
								}
							}
						}
					}

				}
			}
			else {
				return;
			}
		}
	}
	else if (dir == 3) {//위
		if (!iswindBlow) {
			if (x - 1 >= 0) {
				arr[x - 1][y] = temp;
				q.push({ {x - 1,y},temp - 1 });
				visited[x - 1][y] = 1;
				while (!q.empty()) {
					x = q.front().first.first;
					y = q.front().first.second;
					int t = q.front().second;
					q.pop();
					if (t == 0)
						continue;
					int u = 0, r = 0, l = 0, tx, ty;
					if (WALL[x][y]) { //x,y에 벽이 있다면
						wall tmp = m[{x, y}];
						if (tmp.up)
							u = 1;
						if (tmp.right)
							r = 1;
						if (tmp.left)
							l = 1;
					}

					if (!l) { //(x,y) -> (x-1,y-1)
						tx = x, ty = y - 1;
						if (ty >= 0) {
							int flag = 0;
							if (WALL[tx][ty]) {
								wall tmp = m[{tx, ty}];
								if (tmp.up)
									flag = 1;
							}
							if (!flag) {
								tx--;
								if (tx >= 0&&!visited[tx][ty]) {
									arr[tx][ty] = t;
									visited[tx][ty] = 1;
									q.push({ {tx,ty},t - 1 });
								}
							}
						}
					}

					if (!u) { //(x,y) -> (x-1,y)
						tx = x - 1, ty = y;
						if (tx >= 0&&!visited[tx][ty]) {
							arr[tx][ty] = t;
							visited[tx][ty] = 1;
							q.push({ {tx,ty},t - 1 });
						}
					}

					if (!r) { //(x,y) -> (x-1,y+1)
						tx = x, ty = y + 1;
						if (ty < C) {
							int flag = 0;
							if (WALL[tx][ty]) {
								wall tmp = m[{tx, ty}];
								if (tmp.up)
									flag = 1;
							}
							if (!flag) {
								tx--;
								if (tx >= 0&&!visited[tx][ty]) {
									arr[tx][ty] = t;
									visited[tx][ty] = 1;
									q.push({ {tx,ty},t - 1 });
								}
							}
						}
					}

				}
			}
			else {
				return;
			}
		}
		else { //처음 아님
			if (x - 1 >= 0) {
				arr[x - 1][y] += temp;
				q.push({ {x - 1,y},temp - 1 });
				visited[x - 1][y] = 1;
				while (!q.empty()) {
					x = q.front().first.first;
					y = q.front().first.second;
					int t = q.front().second;
					q.pop();
					if (t == 0)
						continue;
					int u = 0, r = 0, l = 0, tx, ty;
					if (WALL[x][y]) { //x,y에 벽이 있다면
						wall tmp = m[{x, y}];
						if (tmp.up)
							u = 1;
						if (tmp.right)
							r = 1;
						if (tmp.left)
							l = 1;
					}

					if (!l) { //(x,y) -> (x-1,y-1)
						tx = x, ty = y - 1;
						if (ty >= 0) {
							int flag = 0;
							if (WALL[tx][ty]) {
								wall tmp = m[{tx, ty}];
								if (tmp.up)
									flag = 1;
							}
							if (!flag) {
								tx--;
								if (tx >= 0&&!visited[tx][ty]) {
									arr[tx][ty] += t;
									visited[tx][ty] = 1;
									q.push({ {tx,ty},t - 1 });
								}
							}
						}
					}

					if (!u) { //(x,y) -> (x-1,y)
						tx = x - 1, ty = y;
						if (tx >= 0&&!visited[tx][ty]) {
							arr[tx][ty] += t;
							visited[tx][ty] = 1;
							q.push({ {tx,ty},t - 1 });
						}
					}

					if (!r) { //(x,y) -> (x-1,y+1)
						tx = x, ty = y + 1;
						if (ty < C) {
							int flag = 0;
							if (WALL[tx][ty]) {
								wall tmp = m[{tx, ty}];
								if (tmp.up)
									flag = 1;
							}
							if (!flag) {
								tx--;
								if (tx >= 0&&!visited[tx][ty]) {
									arr[tx][ty] += t;
									visited[tx][ty] = 1;
									q.push({ {tx,ty},t - 1 });
								}
							}
						}
					}

				}
			}
			else {
				return;
			}
		}
	}
	else {//아래
		if (!iswindBlow) { //처음
			if (x + 1 <R) {
				arr[x + 1][y] = temp;
				q.push({ {x + 1,y},temp - 1 });
				while (!q.empty()) {
					x = q.front().first.first;
					y = q.front().first.second;
					int t = q.front().second;
					q.pop();
					if (t == 0)
						continue;
					int d = 0, r = 0, l = 0, tx, ty;
					if (WALL[x][y]) { //x,y에 벽이 있다면
						wall tmp = m[{x, y}];
						if (tmp.down)
							d = 1;
						if (tmp.right)
							r = 1;
						if (tmp.left)
							l = 1;
					}

					if (!l) { //(x,y) -> (x-1,y-1)
						tx = x, ty = y - 1;
						if (ty >= 0) {
							int flag = 0;
							if (WALL[tx][ty]) {
								wall tmp = m[{tx, ty}];
								if (tmp.down)
									flag = 1;
							}
							if (!flag) {
								tx++;
								if (tx <R&&!visited[tx][ty]) {
									arr[tx][ty] = t;
									visited[tx][ty] = 1;
									q.push({ {tx,ty},t - 1 });
								}
							}
						}
					}

					if (!d) { //(x,y) -> (x-1,y)
						tx = x + 1, ty = y;
						if (tx < R&&!visited[tx][ty]) {
							arr[tx][ty] = t;
							visited[tx][ty] = 1;
							q.push({ {tx,ty},t - 1 });
						}
					}

					if (!r) { //(x,y) -> (x-1,y+1)
						tx = x, ty = y + 1;
						if (ty < C) {
							int flag = 0;
							if (WALL[tx][ty]) {
								wall tmp = m[{tx, ty}];
								if (tmp.down)
									flag = 1;
							}
							if (!flag) {
								tx++;
								if (tx < R&&!visited[tx][ty]) {
									arr[tx][ty] = t;
									visited[tx][ty] = 1;
									q.push({ {tx,ty},t - 1 });
								}
							}
						}
					}

				}
			}
			else {
				return;
			}
		}
		else { //처음 아님
			if (x + 1 < R) {
				arr[x + 1][y] += temp;
				q.push({ {x + 1,y},temp - 1 });
				visited[x+1][y]=1;
				while (!q.empty()) {
					x = q.front().first.first;
					y = q.front().first.second;
					int t = q.front().second;
					q.pop();
					if (t == 0)
						continue;
					int d = 0, r = 0, l = 0, tx, ty;
					if (WALL[x][y]) { //x,y에 벽이 있다면
						wall tmp = m[{x, y}];
						if (tmp.down)
							d = 1;
						if (tmp.right)
							r = 1;
						if (tmp.left)
							l = 1;
					}

					if (!l) { //(x,y) -> (x-1,y-1)
						tx = x, ty = y - 1;
						if (ty >= 0) {
							int flag = 0;
							if (WALL[tx][ty]) {
								wall tmp = m[{tx, ty}];
								if (tmp.down)
									flag = 1;
							}
							if (!flag) {
								tx++;
								if (tx < R&&!visited[tx][ty]) {
									arr[tx][ty] += t;
									visited[tx][ty] = 1;
									q.push({ {tx,ty},t - 1 });
								}
							}
						}
					}

					if (!d) { //(x,y) -> (x-1,y)
						tx = x + 1, ty = y;
						if (tx < R&&!visited[tx][ty]) {
							arr[tx][ty] += t;
							visited[tx][ty] = 1;
							q.push({ {tx,ty},t - 1 });
						}
					}

					if (!r) { //(x,y) -> (x-1,y+1)
						tx = x, ty = y + 1;
						if (ty < C) {
							int flag = 0;
							if (WALL[tx][ty]) {
								wall tmp = m[{tx, ty}];
								if (tmp.down)
									flag = 1;
							}
							if (!flag) {
								tx++;
								if (tx < R&&!visited[tx][ty]) {
									arr[tx][ty] += t;
									visited[tx][ty] = 1;
									q.push({ {tx,ty},t - 1 });
								}
							}
						}
					}

				}
			}
			else {
				return;
			}
		}
	}
}

int xx[4] = { -1,0,1,0 };
int yy[4] = { 0,1,0,-1 };

void tempControl() {

	for (int x = 0; x < R; x++) {
		for (int y = 0; y < C; y++) {
			int u = 0, d = 0, r = 0, l = 0;
			if (WALL[x][y]) {
				wall tmp = m[{x, y}];
				if (tmp.up)
					u = 1;
				if (tmp.down)
					d = 1;
				if (tmp.right)
					r = 1;
				if (tmp.left)
					l = 1;
			}
			for (int i = 0; i < 4; i++) {
				if (u && i == 0)
					continue;
				if (r && i == 1)
					continue;
				if (d && i == 2)
					continue;
				if (l && i == 3)
					continue;
				int tx = x + xx[i], ty = y + yy[i];
				if (tx >= 0 && ty >= 0 && tx < R && ty < C) {
					if (arr[x][y] <= arr[tx][ty])
						continue;
					else {
						
						int gap = abs(arr[x][y] - arr[tx][ty]);
						gap /= 4;
						cp[x][y] -= gap;
						if (cp[x][y] <= 0)
							cp[x][y] = 0;
						cp[tx][ty] += gap;
					}
				}
			}
		}
	}
}

int main(void) {
	fastio();
	cin >> R >> C >> K;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > 0 && arr[i][j] < 5) {
				heater.push_back({ {i,j},arr[i][j] });
				arr[i][j] = 0;
			}
			else if (arr[i][j] == 5) {
				arr[i][j] = 0;
				toSearch.push_back({ i,j });
			}
		}
	}
	cin >> W;
	while (W--) {
		int x, y, t;
		cin >> x >> y >> t;
		x--, y--;
		if (!t) { //(x,y) -> (x-1,y)
			if (!WALL[x][y]) {
				WALL[x][y] = 1;
				m.insert({ {x,y},wall(x,y) });
			}
			if (!WALL[x - 1][y]) {
				WALL[x - 1][y] = 1;
				m.insert({ {x,y},wall(x,y) });
			}
			m[{x, y}].up = 1;
			m[{x - 1, y}].down = 1;
		}
		else { //(x,y) ->(x,y+1)
			if (!WALL[x][y]) {
				WALL[x][y] = 1;
				m.insert({ {x,y},wall(x,y) });
			}
			if (!WALL[x][y + 1]) {
				WALL[x][y + 1] = 1;
				m.insert({ {x,y},wall(x,y) });
			}
			m[{x, y}].right = 1;
			m[{x, y + 1}].left = 1;
		}
	}
	/*for (auto iter = m.begin(); iter != m.end(); iter++) {
		cout << iter->first.first << ' ' << iter->first.second << '\n';
		wall w = iter->second;
		cout << w.up << ' ' << w.right << ' ' << w.down << ' ' << w.left << '\n';
	}*/
	int choco = 0;
	while (choco <= 100) {
		/*바람 불기*/
		for (int i = 0; i < heater.size(); i++) { 
			int x = heater[i].first.first, y = heater[i].first.second;
			int dir = heater[i].second;
			windBlow(x, y, dir);
			if (!iswindBlow)
				iswindBlow = 1;

		}
		
		/*cout << '\n';
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';*/
		arrTocp();
		/*온도 조절*/

		tempControl();

		cpToarr();

		for (int i = 1; i < R-1; i++) {
			if (arr[i][0] > 0)
				arr[i][0]--;
			if (arr[i][C - 1] > 0)
				arr[i][C - 1]--;
		}

		for (int i = 1; i < C - 1; i++) {
			if (arr[0][i] > 0) 
				arr[0][i]--;
			if (arr[R - 1][i] > 0)
				arr[R - 1][i]--;
		}

		if (arr[0][0] > 0)
			arr[0][0]--;
		if (arr[0][C - 1] > 0)
			arr[0][C - 1]--;
		if (arr[R - 1][0] > 0)
			arr[R - 1][0]--;
		if (arr[R - 1][C - 1] > 0)
			arr[R - 1][C - 1]--;

		arrTocp();

		choco++;

		int f = 0;
		for (int i = 0; i < toSearch.size(); i++) {
			if (arr[toSearch[i].first][toSearch[i].second] < K) {
				f = 1;
				break;
			}
		}
		
		if (!f) {
			cout << choco << '\n';
			return 0;
		}
		/*for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
		*/
	}
	cout << 101 << '\n';
	return 0;
}