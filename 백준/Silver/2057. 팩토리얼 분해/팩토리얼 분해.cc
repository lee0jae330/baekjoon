#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

typedef long long ll;

map<int, ll>m;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	m[0] = 1;
	ll n = 1;
	for (int i = 1; i <= 19; i++) {
		n *= i;
		m[i] = n;
	}

	ll num;
	cin >> num;
	while (1) {
		ll tmp = -1;
		int a = -1;
		for (auto[x, y] : m) {
			if (num >= y) {
				a = x;
				tmp = y;
			}
			else {
				break;
			}
		}
		if (tmp == -1) {
			cout << "NO" << '\n';
			return 0;
		}
		num -= tmp;
		if (!num) {
			cout << "YES" << '\n';
			return 0;
		}
		m.erase(a);
	}
	return 0;
}