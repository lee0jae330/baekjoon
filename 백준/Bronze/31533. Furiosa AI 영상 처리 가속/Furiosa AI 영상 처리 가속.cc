#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a;
	double m, n;
	cin >> a >> m >> n;

	double tmp1 = m / a;
	double tmp2 = n / a;

	cout << fixed;
	cout.precision(7);

	if (tmp1 * 2 < tmp2 * 2 && tmp1 * 2 < n) {
		cout << tmp1 * 2 << '\n';
		return 0;
	}

	if (tmp2 * 2 < tmp1 * 2 && tmp2 * 2 < m) {
		cout << tmp2 * 2 << '\n';
		return 0;
	}

	cout << max(n, m) << '\n';
	return 0;
}