#include<iostream>
#include<cmath>
using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int o = 0, t = 0;
	for (int i = 0; i < 3; i++) {
		int num;
		cin >> num;
		if (num == 1)
			o++;
		else
			t++;
	}
	if (o > t)
		cout << 1 << '\n';
	else
		cout << 2 << '\n';
	return 0;
}