#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;

/*void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}*/

int arr[101][101];
int visited[101][101];
int cnt[101][101];

int oddX[6] = { -1,0,1,1,0,-1 };
int oddY[6] = { 0,1,0,-1,-1,-1 };

int evenX[6] = { -1,0,1,1,0,-1 };
int evenY[6] = { 1,1,1,0,-1,0 };

int result = 0;

void bfs(int x, int y,int H,int W) {
	queue<pair<int, int>>q;
	q.push({ x,y });
	visited[x][y] = 1;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 6; i++) {
			if (x % 2==1) {
				int tx = x + oddX[i], ty = y + oddY[i];
				if (tx >= 0 && ty >= 0 && tx < H && ty < W) {
					if (!visited[tx][ty]) {
						if (arr[tx][ty] == 0) {
							cnt[tx][ty]++;
						}
						else {
							visited[tx][ty] = 1;
							q.push({ tx, ty });
						}
					}
				}
				else {
					result++;
				}
			}
			else {
				int tx = x + evenX[i], ty = y + evenY[i];
				if (tx >= 0 && ty >= 0 && tx < H && ty < W) {
					if (!visited[tx][ty]) {
						if (arr[tx][ty] == 0) {
							cnt[tx][ty]++;
						}
						else {
							visited[tx][ty] = 1;
							q.push({ tx, ty });
						}
					}
				}
				else {
					result++;
				}
			}
		}
	}
}

vector<pair<int, int>>v;

bool bfs1(int x, int y, int H, int W) {
	queue<pair<int, int>>q;
	q.push({ x,y });
	visited[x][y] = 1;
	v.push_back({ x,y });
	int flag = 0;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 6; i++) {
			if (x % 2 == 1) {
				int tx = x + oddX[i], ty = y + oddY[i];
				if (tx >= 0 && ty >= 0 && tx < H && ty < W) {
					if (!visited[tx][ty]) {
						if (!arr[tx][ty]) {
							visited[tx][ty] = 1;
							q.push({ tx, ty });
							v.push_back({ tx,ty });
						}
					}
				}
				else {
					flag = 1;
				}
			}
			else {
				int tx = x + evenX[i], ty = y + evenY[i];
				if (tx >= 0 && ty >= 0 && tx < H && ty < W) {
					if (!visited[tx][ty]) {
						if (!arr[tx][ty]) {
							visited[tx][ty] = 1;
							q.push({ tx, ty });
							v.push_back({ tx,ty });

						}
					}
				}
				else {
					flag = 1;
				}
			}
		}
	}
	if (flag)
		return false;
	else
		return true;
}

int main(void) {
	//fastio();
	int W, H;
	scanf("%d %d", &W, &H);
	//cin >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++)
			scanf("%d", &arr[i][j]);
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (arr[i][j] && !visited[i][j]) {
				bfs(i, j, H, W);
			}
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (!arr[i][j] && !visited[i][j]) {
				if (bfs1(i, j, H, W)) {
					for (int k = 0; k < v.size(); k++) {
						cnt[v[k].first][v[k].second] = 0;
					}
				}
				v.clear();
			}
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (cnt[i][j] > 0 && cnt[i][j] < 6)
				result += cnt[i][j];
		}
	}
	printf("%d\n", result);
	//cout << result << '\n';
	return 0;
}