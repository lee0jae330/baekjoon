#include<iostream>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int B, level;
	cin >> B;
	level = 5 * B - 400;
	cout << level << '\n';
	if (level < 100) {
		cout << 1 << '\n';
	}
	else if (level > 100) {
		cout << -1 << '\n';
	}
	else
		cout << 0 << '\n';
	return 0;
}