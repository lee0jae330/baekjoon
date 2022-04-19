#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[31];

int main(void) {
	fastio();
	for (int i = 0; i < 28; i++) {
		int N;
		cin >> N;
		arr[N] = 1;
	}

	for (int i = 1; i <= 30; i++) {
		if (!arr[i]) {
			cout << i << '\n';
		}
	}
	return 0;
}