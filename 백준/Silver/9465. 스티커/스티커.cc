#include<bits/stdc++.h>

using namespace std;

int arr[2][100001];
int dp[2][100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		memset(dp, 0, sizeof(dp));
		int N;
		cin >> N;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> arr[i][j];
			}
		}
		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];

		int sol = max(dp[0][1],dp[1][1]);

		for (int i = 2; i <= N; i++) {
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
			dp[1][i] = max(dp[0][i-1],dp[0][i-2]) + arr[1][i];
			sol = max(sol , max(dp[0][i],dp[1][i]));
		}

		cout << sol <<'\n';
	}
	return 0;
}