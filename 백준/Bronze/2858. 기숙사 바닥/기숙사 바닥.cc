#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int R, B;
	cin >> R >> B;
	int sum = R + B;
	for (int i = 1; i <= sum; i++) {
		if (sum % i) {
			continue;
		}

		int tmp = sum / i;
		int L = max(tmp, i);
		int W = min(tmp, i);
		if ((L - 2) * (W - 2) == B) {
			cout << L << ' ' << W << '\n';
			return 0;
		}
	}
	return 0;
}