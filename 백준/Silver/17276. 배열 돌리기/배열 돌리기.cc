#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[501][501];
int tmp[501][501];
int N;

void reverseClock() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			tmp[i][j] = arr[i][j];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) {
				tmp[N / 2][j] = arr[i][j];
			}
			if (j == N / 2) {
				tmp[i][i] = arr[i][j];
			}
			if (i != j && i + j == N - 1) {
				tmp[i][N / 2] = arr[i][j];
			}
			if (i == N / 2) {
				tmp[N - 1 - j][j] = arr[i][j];
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			arr[i][j] = tmp[i][j];
	}
}

void Clock() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			tmp[i][j] = arr[i][j];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) {
				tmp[i][N/2] = arr[i][j];
			}
			if (j == N / 2) {
				tmp[i][N-1-i] = arr[i][j];
			}
			if (i != j && i + j == N - 1) {
				tmp[N/2][j] = arr[i][j];
			}
			if (i == N / 2) {
				tmp[j][j] = arr[i][j];
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			arr[i][j] = tmp[i][j];
	}
}

int main(void) {
	fastio();
	int T;
	cin >> T;
	while (T--) {
		memset(tmp, 0, sizeof(tmp));
		int d;
		cin >> N>>d;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				cin >> arr[i][j];
		}
		if (d < 0) {
			d = -d;
			
			for (int r = 0; r < d/45; r++) {
				reverseClock();
			}
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++)
					cout << arr[i][j] << ' ';
				cout << '\n';
			}
		}
		else if (d > 0) {
			for (int r = 0; r < d / 45; r++) {
				Clock();
			}
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++)
					cout << arr[i][j] << ' ';
				cout << '\n';
			}
		}
		else {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++)
					cout << arr[i][j] << ' ';
				cout << '\n';
			}
		}
	}
	return 0;
}