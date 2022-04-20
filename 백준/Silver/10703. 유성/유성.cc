#include<iostream>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

char arr[3001][3001];

int main(void) {
	fastio();
	int R, S;
	cin >> R >> S;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < S; j++)
			cin >> arr[i][j];
	}
	
	int gap = 100000;
	for (int i = 0; i < S; i++) {
		int meteor=-1, earth=-1;

		for (int j = 0; j < R; j++) {
			if (arr[j][i] == 'X' && arr[j + 1][i]=='.') {
				meteor = j;
			}
			if (arr[j][i] == '.' && arr[j + 1][i] == '#') {
				earth = j;
				break;
			}
		}

		if (meteor == -1)
			continue;
		gap = min(gap, earth - meteor);
	}
	for (int i = 0; i < S; i++) {
		for (int j = R - 1; j >= 0; j--) {
			if (arr[j][i] == 'X') {
				arr[j + gap][i] = 'X';
				arr[j][i] = '.';
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < S; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
	return 0;
	
}