#include<iostream>
#include<algorithm>

using namespace std;

int dp[101][100001];
pair<int,int>arr[101];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N , K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			dp[i][j] = dp[i-1][j];
			if (j - arr[i].first >= 0) {
				dp[i][j] = max(dp[i][j], dp[i-1][j-arr[i].first]+ arr[i].second);
			}
		}
	}

	cout << dp[N][K] <<'\n';
	return 0;
 
}