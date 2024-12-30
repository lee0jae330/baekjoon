#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> arr;
vector<int> lis;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		arr.clear();
		lis.clear();

		int N, K;
		cin >> N >> K;

		arr.resize(N);

		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		for (int i = 0; i < N; i++) {
			auto iter = lower_bound(lis.begin(), lis.end(), arr[i]);
			if (iter == lis.end()) {
				lis.push_back(arr[i]);
			}
			else {
				*iter = arr[i];
			}
		}
		
		cout << "Case #" << t <<'\n';

		if (lis.size() >= K) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
}