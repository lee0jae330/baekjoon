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
	int a, b, c;
	cin >> a >> b >> c;
	if (a > b)
		swap(a, b);
	if (b > c)
		swap(b, c);
	cin >> a >> b >> c;
	if (a == b && b == c)
		cout << 2 << '\n';

	else if (c* c == a * a + b * b)
		cout << 1 << '\n';
	else
		cout << 0 << '\n';
	return 0;
}