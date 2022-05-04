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
	int sum = 91;
	sum += a + 3 * b + c;
	cout << "The 1-3-sum is " << sum << '\n';
	return 0;
}