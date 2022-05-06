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
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		sum += num;
	}
	sum -= N;
	sum++;
	cout << sum << '\n';
	return 0;
}