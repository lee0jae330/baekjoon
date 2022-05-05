#include<iostream>

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
	if (a == b || b == c || a == c)
		cout << "S" << '\n';
	else {
		if (a == b + c || b == a + c || c == a + b)
			cout << "S" << '\n';
		else
			cout << "N" << '\n';
	}
	return 0;
}