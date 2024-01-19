#include<bits/stdc++.h>

using namespace std;

long long dp[1000001];

long long mod = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
	}

	cout << dp[N] << '\n';
	return 0;
}