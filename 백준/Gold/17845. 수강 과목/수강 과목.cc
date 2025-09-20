#include<iostream>
#include<utility>
#include<algorithm>

using namespace std;

int dp[1001][10001];
pair<int, int>arr[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= K; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = dp[i-1][j];
			if (j - arr[i].second >= 0) {
				dp[i][j] = max(dp[i][j], dp[i-1][j-arr[i].second]+arr[i].first);
			}
		}
	}

	cout << dp[K][N];
	return 0;
}