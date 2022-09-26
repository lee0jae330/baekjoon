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
		int x, y, z;
		cin >> x >> y >> z;
		x %= 2, y %= 2, z %= 2;
		if (x && y && z)
			cout << 'B' << '\n';
		else if (!x && !y && !z)
			cout << 'R' << '\n';
		else if ((!x && y && z) || (x && !y && z) || (x && y && !z))
			cout << 'B' << '\n';
		else
			cout << 'R' << '\n';
	}
	return 0;
}