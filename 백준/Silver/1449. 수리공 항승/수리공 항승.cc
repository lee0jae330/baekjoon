#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, L;
	cin >> N >> L;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());
	int tmp = L;
	int cnt = 1;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (arr[j] - arr[i] > L - 1) {
				cnt++;
				i = j-1;
				break;
			}
		}
	}
	cout << cnt <<'\n';
}	