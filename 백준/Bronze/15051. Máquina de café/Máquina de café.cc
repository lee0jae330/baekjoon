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
	int sum = y*2+z*4;
	sum = min(sum, x * 2 + z * 2);
	sum = min(sum, x * 4 + y * 2);
	cout << sum << '\n';
	return 0;

}