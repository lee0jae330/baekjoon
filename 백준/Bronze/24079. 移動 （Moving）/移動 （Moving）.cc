#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int x, y, z;
	cin >> x >> y >> z;
	if ((x + y) * 60 <= z * 60 + 30)
		cout << 1 << '\n';
	else
		cout << 0 << '\n';
	return 0;

}