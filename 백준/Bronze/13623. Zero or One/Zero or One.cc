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
	int a, b, c;
	cin >> a >> b >> c;
	if (a && b && c || !a && !b && !c) {
		cout << "*" << '\n';
	}
	else {
		if (a == b)
			cout << 'C' << '\n';
		else if (b == c)
			cout << 'A' << '\n';
		else
			cout << 'B' << '\n';
	}
	return 0;
}