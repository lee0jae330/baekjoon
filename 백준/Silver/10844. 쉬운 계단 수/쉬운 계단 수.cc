#include<bits/stdc++.h>

using namespace std;

long long dp[101][11];
long long mod = 1e9;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	dp[1][0] =0;
	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j - 1 >= 0) {
				dp[i][j]+=dp[i-1][j-1];
				dp[i][j]%=mod;
			}
			if (j + 1 <= 9) {
				dp[i][j] += dp[i-1][j+1];
				dp[i][j] %= mod;
			}
		}
	}

	long long sol = 0;
	for (int i = 0; i <= 9; i++) {
		sol += dp[N][i];
		sol%=mod;
	}
	cout << sol <<'\n';
	return 0;
}