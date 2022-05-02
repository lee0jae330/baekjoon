#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int result = 0;
	char c;
	for (int i = 0; i < 6; i++) {
		cin >> c;
		if (c == 'W')
			result++;
	}
	if (result >= 5)
		cout << 1 << '\n';
	else if (result >= 3)
		cout << 2 << '\n';
	else if (result >= 1)
		cout << 3 << '\n';
	else
		cout << -1 << '\n';
	
	return 0;
}