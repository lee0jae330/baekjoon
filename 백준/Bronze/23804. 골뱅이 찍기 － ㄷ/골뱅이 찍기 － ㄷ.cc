#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N * 5; j++)
			cout << '@';
		cout << '\n';
	}
	for (int i = 0; i < 3 * N; i++) {
		for (int j = 0; j < N; j++)
			cout << '@';
		cout << '\n';
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N * 5; j++)
			cout << '@';
		cout << '\n';
	}
	return 0;
}