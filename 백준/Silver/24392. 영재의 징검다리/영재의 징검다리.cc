#include<bits/stdc++.h>

using namespace std;

int arr[1001][1001];
int dp[1001][1001];
int mod = 1e9+7;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N,M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (i == 0 && arr[i][j]) {
				dp[i][j] = 1;
			}
		}
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j]) {
				dp[i][j] = dp[i-1][j] % mod;
				if (j - 1 >= 0) {
					dp[i][j]+=dp[i-1][j-1];
					dp[i][j] %=mod;
				}
				if (j + 1 < M) {
					dp[i][j] += dp[i-1][j+1];
					dp[i][j] %=mod;
				}
			}
		}
	}

	long long sol =0;

	for (int i = 0; i < M; i++) {
		sol += dp[N-1][i];
		sol %= mod;
	}

	cout << sol <<'\n';
	return 0;
}