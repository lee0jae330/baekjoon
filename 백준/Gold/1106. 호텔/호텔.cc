#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>

using namespace std;

int C, N;

const int INF = 1 << 31 - 1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> C >> N;

	vector<int>dp(2001, INF);
	vector<pair<int, int>>v(N);
	dp[0] = 0;

	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
	}

	for (int i = 1; i <= 2000; i++) {
		for (auto [cost, value] : v) {
			if (i - value >= 0) {
				dp[i] = min(dp[i], dp[i - value] + cost);
			}
		}
	}

	int sol = dp[C];
	for (int i = C + 1; i <= 2000; i++) {
		sol = min(sol, dp[i]);
	}

	cout << sol <<'\n';
	return 0;

}