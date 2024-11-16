#include<iostream>

using namespace std;

typedef long long ll;

int arr[100002]; // arr[i] : 1라운드 참여 직후 ~ i라운드 참여 직전까지 K 보다 레이팅이 낮은 라운드 수


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, M, K, X;
	cin >> N >> M >> K >> X;
	ll sum = X;
	int tmp;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		sum += tmp;
		if (sum >= K) {
			arr[i + 1] = arr[i];
		}
		else {	
			arr[i + 1] = arr[i] + 1;
		}
	}
	arr[N + 1] = (sum >= K) ? arr[N] : arr[N] + 1;
	while (M--) {
		int l, r;
		cin >> l >> r;
		cout << arr[r] - arr[l] << '\n';
	}
	return 0;
}