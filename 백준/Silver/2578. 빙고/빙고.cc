#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[5][5];

int bingo(int num) {
	int flag = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[i][j] == num) {
				arr[i][j] = -1;
				flag = 1;
				break;
			}
		}
		if (flag)
			break;
	}
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		flag = 0;
		for (int j = 0; j < 5; j++) {
			if (arr[i][j] != -1) {
				flag = 1;
				break;
			}
		}
		if (!flag) {
			cnt++;
		}
	}
	for (int i = 0; i < 5; i++) {
		flag = 0;
		for (int j = 0; j < 5; j++) {
			if (arr[j][i] != -1) {
				flag = 1;
				break;
			}
		}
		if (!flag) {
			cnt++;
		}
	}
	flag = 0;
	for (int i = 0; i < 5; i++) {
		if (arr[i][i] != -1) {
			flag = 1;
			break;
		}
	}
	if (!flag)
		cnt++;
	flag = 0;
	for (int i = 0; i < 5; i++) {
		if (arr[i][4 - i] != -1) {
			flag = 1;
			break;
		}
	}
	if (!flag)
		cnt++;
	return cnt;
}

int main(void) {
	fastio();
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
	int seq = 0;
	int result = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int num;
			cin >> num;
			if (bingo(num) >= 3&&!result) {
				result = 5 * i + j + 1;
			}
		}
	}
	cout << result << '\n';
	return 0;
}