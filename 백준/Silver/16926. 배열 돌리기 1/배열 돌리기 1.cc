#include<iostream>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[301][301];

int main(void) {
	fastio();
	int N,M,R;
	cin >> N>>M>>R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}
	int num = min(N, M);
	num /= 2;
	for (int i = 0; i < num; i++) {
		for (int r = 0; r < R; r++) { //회전수
			int tmp = arr[i][i];
			for (int j = i + 1; j < M - i; j++) {
				arr[i][j - 1] = arr[i][j];
			}

			for (int j = i + 1; j < N - i; j++) {
				arr[j - 1][M - i - 1] = arr[j][M - i - 1];
			}

			for (int j = M - i - 2; j >= i; j--) {
				arr[N - i - 1][j + 1] = arr[N - i - 1][j];
			}

			for (int j = N - i - 2; j >= i + 1; j--) {
				arr[j + 1][i] = arr[j][i];
			}
			arr[i + 1][i] = tmp;


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