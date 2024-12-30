#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int>arr;
vector<int>lis;

const int SIZE = (int)3 * 1e5 + 1;
int dp1[SIZE];
int dp2[SIZE];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, Q;
	cin >> N >> Q;
	arr.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		auto iter = lower_bound(lis.begin(), lis.end(), arr[i]);
		if (iter == lis.end()) {
			dp1[i] = lis.size() + 1;

			lis.push_back(arr[i]);
		}
		else {
			*iter = arr[i];
			dp1[i] = iter - lis.begin() + 1;
		}
	}

	lis.clear();
	reverse(arr.begin(), arr.end());

	for (auto& num : arr) {
		num *= -1;
	}

	for (int i = 0; i < N; i++) {
		auto iter = lower_bound(lis.begin(), lis.end(), arr[i]);
		if (iter == lis.end()) {
			dp2[N - i - 1] = lis.size() + 1;
			lis.push_back(arr[i]);
		}
		else {
			*iter = arr[i];
			dp2[N - i - 1] = iter - lis.begin() + 1;
		}
	}

	while (Q--) {
		int num;
		cin >> num;
		num--;
		cout << dp1[num] + dp2[num] - 1 << '\n';
	}

	return 0;

}

