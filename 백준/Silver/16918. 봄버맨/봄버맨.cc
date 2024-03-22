#include<bits/stdc++.h>

using namespace std;

char arr[201][201];
char cp[201][201];

int t[201][201];
int cp_t[201][201];

int xx[4] = { 0,1,0,-1 };
int yy[4] = { 1,0,-1,0 };

int R, C, N;

void stay() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == 'O') {
				t[i][j]++;
			}
		}
	}
}

void setup() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == 'O') {
				t[i][j]++;
			}
			else {
				arr[i][j] = 'O';
				t[i][j] = 0;
			}
		}
	}
}

void boom() {

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cp[i][j] = arr[i][j];
			cp_t[i][j] = t[i][j];
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == 'O') {
				if (t[i][j] >= 2) {
					cp[i][j] = '.';
					cp_t[i][j] = 0;
					for (int k = 0; k < 4; k++) {
						int tx = i + xx[k];
						int ty = j + yy[k];
						if (tx < 0 || ty < 0 || tx >= R || ty >= C) {
							continue;
						}
						cp[tx][ty] = '.';
						cp_t[tx][ty] = 0;
					}
				}
				else {
					cp_t[i][j] ++;
				}
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			arr[i][j] = cp[i][j];
			t[i][j] = cp_t[i][j];
		}
	}
}

void print() {
	cout << '\n';
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << t[i][j];
		}
		cout << '\n';
	}
	cout << '\n';

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> R >> C >> N;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'O') {
				t[i][j] = 0;
			}
		}
	}

	//print();

	for (int tm = 1; tm <= N; tm++) {
		if (tm == 1) {
			stay();
	//		print();
		}
		else {
			if (tm % 2 == 0) {
				setup();
	//			print();
			}
			else {
				boom();
	//			print();
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
	return 0;
}