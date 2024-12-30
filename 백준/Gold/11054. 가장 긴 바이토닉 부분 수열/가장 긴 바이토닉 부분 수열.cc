#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int>arr;
int dp1[1001];
int dp2[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	arr.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		dp1[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp1[i] = max(dp1[i], dp1[j] +1);
			}
		}
	}

	reverse(arr.begin(), arr.end());

	for (int i = 0; i < N; i++) {
		dp2[i]=1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp2[i] = max(dp2[i], dp2[j] +1);
			}
		}
	}

	reverse(dp2, dp2+N);

	int sol = -1;

	for (int i = 0; i < N; i++) {
		sol = max(sol, dp1[i]+dp2[i]-1);
	}
	cout << sol <<'\n';
	return 0;
}