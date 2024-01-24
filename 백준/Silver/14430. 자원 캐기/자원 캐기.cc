#include<bits/stdc++.h>

using namespace std;

int arr[301][301];
int dp[301][301];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N,M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}

	int sol =0;

	for (int i = 1; i <= N; i++) {
		dp[i][1] = dp[i-1][1]+arr[i][1];
		sol = max(sol, dp[i][1]);
	}

	for (int i = 1; i <= M; i++) {
		dp[1][i] = dp[1][i-1] + arr[1][i];
		sol = max(sol, dp[1][i]);
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= M; j++) {
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + arr[i][j];
			sol = max(sol,dp[i][j]);
		}
	}

	cout << sol <<'\n';

	return 0;
}