#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[501][501];

int main(void) {
	fastio();
	int H, W;
	cin >> H >> W;
	for (int i = 0; i < W; i++) {
		int num;
		cin >> num;
		int tmp = H-1;
		for (int j = 0; j < num; j++) {
			arr[tmp--][i] = 1;
		}
	}
	
	int result = 0;
	int l=0;
	for (int i = H - 1; i >= 0; i--) {
		int	cnt = 0;
		l = 0;
		for (int j = 0; j < W; j++) {
			if (arr[i][j]) {
				if (!l) {
					l = 1;
				}
				else {
					result += cnt;
					cnt = 0;
				}
			}
			else {
				if (l)
					cnt++;
			}
		}
	}
	cout << result << '\n';
	return 0;
}