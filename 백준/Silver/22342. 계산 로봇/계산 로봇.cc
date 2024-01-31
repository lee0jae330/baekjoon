#include<bits/stdc++.h>

using namespace std;

int M, N;

char arr[2001][2001];
int save[2001][2001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int M, N;
	cin >> M >> N;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= M; i++) {
		save[i][0] = 0;
	}

	int sol = 0;
	

	for (int j = 2; j <= N; j++) {
		for (int i = 1; i <= M; i++) {
			int tmp = -1;
			for (int a = max(1, i - 1); a <= min(M,i + 1); a++) {
				tmp = max(save[a][j - 1]+(arr[a][j-1]-'0'), tmp);
			}
			save[i][j] = tmp;
			sol = max(sol, save[i][j]);
		}
	}

	cout << sol << '\n';
	return 0;
}