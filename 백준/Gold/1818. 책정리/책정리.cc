#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> arr;
vector<int> lis;

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
		auto iter = lower_bound(lis.begin(), lis.end(), arr[i]);
		if (iter == lis.end()) {
			lis.push_back(arr[i]);
		}
		else {
			*iter = arr[i];
		}
	}

	cout << N - lis.size() <<'\n';
	return 0;
}