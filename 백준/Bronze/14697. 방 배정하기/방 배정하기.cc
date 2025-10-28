#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int A, B, C, D;
	cin >> A >> B >> C >> D;

	if (D % C == 0) {
		cout << 1 << '\n';
		return 0;
	}

	int c = D / C;
	for (int i = 0; i <= c; i++) {
		int d = D - i * C;
		if (d % B == 0) {
			cout << 1 << '\n';
			return 0;
		}

		int b = d / B;

		for (int j = 0; j <= b; j++) {
			int dd = d - j * B;
			if (dd % A == 0) {
				cout << 1 << '\n';
				return 0;
			}
		}

		d = D - i * C;
		if (d % A == 0) {
			cout << 1 << '\n';
			return 0;
		}

		int a = d / A;
		for (int j = 0; j <= a; j++) {
			int dd = d - j * A;
			if (dd % B == 0) {
				cout << 1 << '\n';
				return 0;
			}
		}

	}

	cout << 0 << '\n';
	return 0;
}