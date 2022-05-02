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
	int a, b;
	cin >> a >> b;
	if (a == b)
		if (a)
			cout << "Even " << a * 2 << '\n';
		else
			cout << "Not a moose" << '\n';
	else {
		cout << "Odd " << max(a, b) * 2 << '\n';
	}
	return 0;
}