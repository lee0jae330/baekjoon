#include<iostream>
#include<vector>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[11][101];

int main(void) {
	fastio();
	int M, N;
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	int cnt = 0;

	for (int i = 0; i < M - 1; i++) {
		for (int j = i + 1; j < M; j++) {
			int flag = 0;

			for (int k = 0; k < N - 1; k++) {
				for (int l = k + 1; l < N; l++) {
					if((arr[i][k] < arr[i][l]&&arr[j][k]<arr[j][l])||(arr[i][k]==arr[i][l]&&arr[j][k]==arr[j][l])||(arr[i][k]>arr[i][l]&&arr[j][k]>arr[j][l]))
						continue;
					else {
						flag=1;
						break;
					}
				}
				if(flag)
					break;
			}
			if (!flag)
				cnt++;
		}
	}
	cout << cnt <<'\n';
	return 0;
}