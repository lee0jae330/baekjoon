#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int dir[3][2] = {{0, -1}, {1, 0}, {0, 1}};

class Main {
private:
    int N, M;
    vector<vector<char>> board;
    queue<vector<int>> que;
    vector<vector<bool>> isVisited;
    int res;

    void execBFS() {
        while (!que.empty()) {
            vector<int> cur = que.front();
            que.pop();

            if (cur[0] == N - 1) {
                res = cur[2];
                return;
            }

            for (int i = 0; i < 3; i++) {
                int nX = cur[0] + dir[i][0];
                int nY = cur[1] + dir[i][1];

                if (nX < 0 || nX >= N || nY < 0 || nY >= M) {
                    continue;
                }
                if (board[nX][nY] != 'S') {
                    continue;
                }
                if (isVisited[nX][nY]) {
                    continue;
                }

                que.push({nX, nY, cur[2] + 1});
                isVisited[nX][nY] = true;
            }
        }
    }

public:
    void solution() {
        while (true) {
            cin >> N >> M;

            if (N == 0 && M == 0) {
                break;
            }

            board.assign(N, vector<char>(M));
            for (int i = 0; i < N; i++) {
                string input;
                cin >> input;
                for (int j = 0; j < M; j++) {
                    board[i][j] = input[j];
                }
            }

            for (int i = 0; i < N; i++) {
                for (int j = M - 1; j >= 0; j--) {
                    if (board[i][j] == 'S') {
                        if ((j == 0 || j == N - 1)) {
                            if (j < M - 2) {
                                board[i][j + 1] = 'S';
                                break;
                            }
                        } else {
                            if (j < M - 1) {
                                board[i][j + 1] = 'S';
                                break;
                            }
                        }
                    }
                }
            }

            que = queue<vector<int>>();
            isVisited.assign(N, vector<bool>(M, false));

            for (int i = 1; i < M - 1; i++) {
                if (board[0][i] == 'S') {
                    que.push({0, i, 1});
                    isVisited[0][i] = true;
                }
            }

            execBFS();

            cout << res << "\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Main main;
    main.solution();

    return 0;
}