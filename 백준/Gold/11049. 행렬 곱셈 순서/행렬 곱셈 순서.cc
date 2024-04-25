#include<bits/stdc++.h>

using namespace std;

int N;
int arr[501][2];
long long dp[501][501];

long long INF = INT32_MAX;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int row, col;
		cin >> row >> col;
		arr[i][0] = row;
		arr[i][1] = col;
	}

	for (int i = 0; i <= 500; i++) {
		for (int j = 0; j <= 500; j++) {
			if(i==j)
				continue;
			dp[i][j] = INF;
		}
	}

	for (int cnt = 1; cnt <= N - 1; cnt++) {
		for (int i = 1; i <= N-cnt; i++) {
			for (int k = 1; k <= i + cnt - 1; k++) {
				dp[i][i+cnt] = min(dp[i][i+cnt], dp[i][k]+dp[k+1][i+cnt]+arr[i][0]*arr[k][1]*arr[i+cnt][1]);
			}
		}
	}

	cout << dp[1][N]<<'\n';
	return 0;
}