#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int s, a, b;
	cin >> s >> a >> b;
	s -= a;
	int flag = 0;
	if (s <= 0) {
		cout << 250 << '\n';
		return 0;
	}
	if (s % b)
		flag = 1;
	cout << 250 + 100 * (s / b + flag) << '\n';
	return 0;

}