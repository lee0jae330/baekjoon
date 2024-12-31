#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
vector<int>arr;
vector<int>lis;

int dp1[2001];
int dp2[2001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	arr.resize(N);
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	reverse(arr.begin(), arr.end());
	for (int& num : arr) {
		num *=-1;
	}

	for (int i = 0; i < N; i++) {
		auto iter = lower_bound(lis.begin(), lis.end(), arr[i]);
		if (iter == lis.end()) {
			dp1[i] = lis.size() + 1;
			lis.push_back(arr[i]);
		}
		else {
			dp1[i] = iter - lis.begin() + 1;
			*iter = arr[i];
		}
	}

	for (int& num : arr) {
		num *= -1;
	}
	lis.clear();

	for (int i = 0; i < N; i++) {
		auto iter = lower_bound(lis.begin(), lis.end(), arr[i]);
		if (iter == lis.end()) {
			dp2[i] = lis.size() + 1;
			lis.push_back(arr[i]);
		}
		else {
			dp2[i] = iter - lis.begin() + 1;
			*iter = arr[i];
		}
	}

	int sol =0;
	for (int i = 0; i < N; i++) {
		sol = max(sol, dp1[i]+dp2[i] -1);
	}
	cout << sol <<'\n';

	return 0;
}