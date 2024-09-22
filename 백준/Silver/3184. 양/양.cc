#include <iostream>
#include <queue>
#include <utility>
#include<tuple>

using namespace std;

char arr[251][251];
int visited[251][251];

int xx[4] = {0, 1, 0, -1};
int yy[4] = {1, 0, -1, 0};

int R, C;
int wolf, sheep;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;
    int w = 0, s = 0;
    if (arr[x][y] == 'o') {
        s++;
    } else if (arr[x][y] == 'v') {
        w++;
    }
    while (!q.empty()) {
        tie(x, y) = q.front(); 
        q.pop();
        for (int i = 0; i < 4; i++) {
            int tx = x + xx[i], ty = y + yy[i];
            if (tx < 0 || ty < 0 || tx >= R || ty >= C || visited[tx][ty] || arr[tx][ty] == '#') {
                continue;
            }
            if (arr[tx][ty] == 'o')
                s++;
            else if (arr[tx][ty] == 'v')
                w++;
            visited[tx][ty] = 1;
            q.push({tx, ty});
        }
    }
    if (s > w) {
        sheep += s;
    } else {
        wolf += w;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j] != '#' && !visited[i][j]) {
                bfs(i, j);
            }
        }
    }

    cout << sheep << ' ' << wolf << '\n';
    return 0;
}