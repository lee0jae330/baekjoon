#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int>arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N,S;
	cin >> N >> S;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(),arr.end());
	int cnt =0;
	for (int i = 0; i < N; i++) {
		for (int j = N-1; j > i; j--) {
			if (arr[i] + arr[j] <= S) {
				cnt++;
			}
		}
	}
	cout << cnt <<'\n';
	return 0;
}