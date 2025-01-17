#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

int arr[1001][1001];
int N;
ll sum = 0;

bool canRun(int length) {
	ll cnt = 0;
	ll standard = sum % 2 == 0 ? (sum / 2) : (sum / 2) + 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cnt += min(arr[i][j], length);
			if (cnt >= standard) {
				return true;
			}
		}
	}
	return false;
}

int search(int right) {
	int left = 1;
	int result = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (canRun(mid)) {
			result = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	int mx = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			sum += arr[i][j];
			mx = max(mx, arr[i][j]);
		}
	}

	cout << search(mx) << '\n';
	return 0;
}