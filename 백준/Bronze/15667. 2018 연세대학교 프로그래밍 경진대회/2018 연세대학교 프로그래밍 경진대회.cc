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
	for (int i = 0; i < 1000; i++) {
		if (i * i + i + 1 == N) {
			cout << i << '\n';
			return 0;
		}
	}
	return 0;
}