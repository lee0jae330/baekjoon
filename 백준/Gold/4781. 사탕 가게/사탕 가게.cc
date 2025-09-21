#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<cstring>
#include<memory.h>
#include<cmath>

using namespace std;

int dp[10001];
vector<pair<int, int>> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (1) {
		memset(dp, 0, sizeof(dp));
		v.clear();
		int N;
		double M;
		cin >> N >> M;

		if (N == 0 && M == 0) {
			return 0;
		}

		for (int i = 1; i <= N; i++) {
			int cal;
			double money;
			cin >> cal >> money;
			v.push_back({ cal, round(money * 100) });
		}

		int m = round(M * 100);
		for (int i = 1; i <= M * 100; i++) {
			for (auto [cal, money] : v) {
				if (i - money >= 0) {
					dp[i] = max(dp[i], dp[i-money] + cal);
				}
			}
		}
		cout << dp[m] << '\n';
	}
	return 0;
}