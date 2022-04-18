#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}
int N, M, R;

int arr[101][101];
int tmp[101][101];

void move1() {
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < M; j++) {
			swap(arr[i][j], arr[N - i - 1][j]);
		}
	}
}

void move2() {
	for (int i = 0; i < M / 2; i++) {
		for (int j = 0; j < N; j++) {
			swap(arr[j][i], arr[j][M - i - 1]);
		}
	}
}

void move3() {
	memset(tmp, 0, sizeof(tmp));
	for (int i = 0; i < M; i++) {
		for (int j = N - 1; j >= 0; j--) {
			tmp[i][N - 1 - j] = arr[j][i];
		}
	}
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = tmp[i][j];
		}
	}
	swap(N, M);
}

void move4() {
	memset(tmp, 0, sizeof(tmp));
	for (int i = M - 1; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			tmp[M - 1 - i][j] = arr[j][i];
		}
	}
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = tmp[i][j];
		}
	}
	swap(N, M);
}


int main(void) {
	fastio();
	cin >> N >> M >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	for (int x = 0; x < R; x++) {
		int dir;
		cin >> dir;
		if (dir == 1) {
			move1();
		}
		else if (dir == 2) {
			move2();
		}
		else if (dir == 3) {
			move3();
		}
		else if (dir == 4) {
			move4();
		}
		else if (dir == 5) {
			for (int i = 0; i < N / 2; i++) {
				for (int j = 0; j < M / 2; j++) {
					tmp[i][j] = arr[i][j];
				}
			}

			for (int i = N / 2; i < N; i++) {
				for (int j = 0; j < M / 2; j++) {
					arr[i - N / 2][j] = arr[i][j];
				}
			}

			for (int i = N / 2; i < N; i++) {
				for (int j = M / 2; j < M; j++) {
					arr[i][j - M / 2] = arr[i][j];
				}
			}

			for (int i = 0; i < N / 2; i++) {
				for (int j = M / 2; j < M; j++) {
					arr[i + N / 2][j] = arr[i][j];
				}
			}

			for (int i = 0; i < N / 2; i++) {
				for (int j = 0; j < M / 2; j++) {
					arr[i][j + M / 2] = tmp[i][j];
				}
			}
		}
		else {
			for (int i = 0; i < N / 2; i++) {
				for (int j = 0; j < M / 2; j++) {
					tmp[i][j] = arr[i][j];
				}
			}

			for (int i = 0; i < N / 2; i++) {
				for (int j = M / 2; j < M; j++) {
					arr[i][j - M / 2] = arr[i][j];
				}
			}

			for (int i = N / 2; i < N; i++) {
				for (int j = M / 2; j < M; j++) {
					arr[i - N / 2][j] = arr[i][j];
				}
			}

			for (int i = N / 2; i < N; i++) {
				for (int j = 0; j < M / 2; j++) {
					arr[i][j + M / 2] = arr[i][j];
				}
			}

			for (int i = 0; i < N / 2; i++) {
				for (int j = 0; j < M / 2; j++) {
					arr[i + N / 2][j] = tmp[i][j];
				}
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << arr[i][j] << ' ';
		cout << '\n';
	}

	cout << '\n';
	return 0;
}