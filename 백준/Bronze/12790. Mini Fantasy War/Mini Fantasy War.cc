#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int T;
	cin >> T;
	while (T--) {
		int hp, mp, atk, def;
		cin >> hp >> mp >> atk >> def;
		int h, m, a, d;
		cin >> h >> m >> a >> d;
		hp += h, mp+= m, atk += a, def += d;

		if (hp < 1)
			hp = 1;
		if (mp < 1)
			mp = 1;
		if (atk < 0)
			atk = 0;

		cout << 1 * hp + 5 * mp + 2 * atk + 2 * def << '\n';

	}
	return 0;
}