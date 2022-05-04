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
	a += b;
	if (a > 12)
		a %= 12;
	if (!a)
		a += 12;
	cout << a << '\n';
	return 0;

}