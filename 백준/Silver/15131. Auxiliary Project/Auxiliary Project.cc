#include<bits/stdc++.h>

using namespace std;

int dp[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	
	dp[2]=1;
	dp[3]=7;
	dp[4]=4;

	for (int i = 5; i <= N; i++) {
		if (i - 2 > 0) {
			dp[i] = dp[i-2]+1;
		}
		if (i - 3 > 0) {
			dp[i] = max(dp[i],7+dp[i-3]);
		}
		if (i - 4 > 0) {
			dp[i] = max(dp[i],4+dp[i-4]);
		}
	}
	cout << dp[N] <<'\n';
	return 0;

}