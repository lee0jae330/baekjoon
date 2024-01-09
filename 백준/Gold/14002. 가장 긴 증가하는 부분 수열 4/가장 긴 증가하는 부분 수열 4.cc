#include<bits/stdc++.h>

using namespace std;

int arr[1001];
int dp[1001];
int pre[1001];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}

	int sol = -1;
	int idx = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j]+1;
					pre[i]= j;
				}
			}
		}

		if (sol < dp[i]) {
			sol = dp[i];
			idx = i;
		}
	}
	cout << sol <<'\n';

	int cur = idx;

	stack<int>s;

	while (1){
		if(!cur)
			break;
		s.push(arr[cur]);
		cur = pre[cur];
	}

	while (!s.empty()) {
		cout << s.top() <<' ';
		s.pop();
	}

	return 0;
}