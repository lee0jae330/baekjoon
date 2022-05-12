#include<iostream>
#include<string>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int sum[101];

int main(void) {
	fastio();
	sum[1] = 1;
	for (int i = 3; i < 100; i += 2) {
		sum[i] = sum[i - 2] + i;
	}
	int T;
	cin >> T;
	while (T--) {
		int num;
		cin >> num;
		cout << sum[num] << '\n';
	}
	return 0;
}