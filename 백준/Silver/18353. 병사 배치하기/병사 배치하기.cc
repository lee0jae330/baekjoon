#include<iostream>
#include<algorithm>

using namespace std;

const int SIZE = (int)2 * 1e3 + 1;
int arr[SIZE];
int dp[SIZE];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int sol = 0;

	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		sol = max(sol, dp[i]);
	}
	
	cout << N - sol << '\n';
	return 0;
}