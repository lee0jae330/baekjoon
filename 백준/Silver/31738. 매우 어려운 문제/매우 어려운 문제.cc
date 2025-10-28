#include<iostream>

typedef long long ll;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll N, M;
	cin >> N >> M;
	if (N >= M) {
		cout << 0 << '\n';
		return 0;
	}
	ll tmp = 1;
	for (int i = 1; i <= N; i++) {
		tmp *= i;
		tmp %= M;
	}
	tmp %= M;
	cout << tmp;
	return 0;
}