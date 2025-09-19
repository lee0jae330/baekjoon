#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a1, a0, c1, c2, n0;

	cin >> a1 >> a0 >> c1 >> c2 >> n0;

	for (int i = n0; i <= 1e5; i++) {
		int f = a1 * i + a0;
		int c1g = c1 * i;
		int c2g = c2 * i;
		if (!(f >= c1g && f <= c2g)) {
			cout << 0 <<'\n';
			return 0;
		}
	}

	cout << 1 <<'\n';
	return 0;

}