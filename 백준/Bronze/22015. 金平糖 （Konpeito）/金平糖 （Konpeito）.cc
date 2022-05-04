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
	int x, y, z;
	cin >> x >> y >> z;
	int mx = max(x, y);
	mx = max(mx, z);
	cout << mx - x + mx - y + mx - z << '\n';
	return 0;

}