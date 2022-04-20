#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[100001];

int main(void) {
	fastio();
	int N;
	long long K;
	cin >> N >> K;
	long long total = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		total += arr[i];
	}
	if (K >= total) {
		K -= total;
		for (int i = N - 1; i >= 0; i--) {
			if (K > arr[i])
				K -= arr[i];
			else if (K == arr[i]) {
				cout << i << '\n';
				return 0;
			}
			else {
				cout << i+1 << '\n';
				return 0;
			}
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			if (K > arr[i])
				K -= arr[i];
			else if (K == arr[i]) {
				cout << i + 2 << '\n';
				return 0;
			}
			else {
				cout << i+1 << '\n';
				return 0;
			}
		}
	}
	return 0;
}