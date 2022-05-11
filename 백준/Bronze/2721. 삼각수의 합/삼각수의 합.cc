#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[302];
int W[301];

int main(void) {
	fastio();
	arr[1] = 1;
	for (int i = 2; i <= 301; i++) {
		arr[i] += arr[i - 1] + i;
	}
	W[1] = arr[2];
	for (int i = 2; i <= 300; i++) {
		W[i] += W[i - 1] + i * arr[i + 1];
	}
	int T;
	cin >> T;
	while (T--) {
		int num;
		cin >> num;
		cout << W[num]<<'\n';
	}
	return 0;
}