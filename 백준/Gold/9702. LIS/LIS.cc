#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int SIZE = 501;
int arr[SIZE];
vector<int>lis;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		lis.clear();
		memset(arr, 0, sizeof(arr));
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		int total = 0;

		for (int i = 0; i < N; i++) {
			lis.clear();
			for (int j = i; j < N; j++) {
				auto iter = lower_bound(lis.begin(), lis.end(), arr[j]);
				if (iter == lis.end()) {
					lis.push_back(arr[j]);
				}
				else {
					*iter = arr[j];
				}
				total += lis.size();
			}
		}

		cout << "Case #" << t << ": " << total << '\n';
	}
	return 0;
}