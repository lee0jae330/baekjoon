#include<iostream>
#include<algorithm>

using namespace std;

int main(void) {
	int a, b,c;
	cin >> a >> b >> c;
	int x, y, z;
	cin >> x >> y >> z;

	x -= a, y -= b, z -= c;
	int sum = 0;
	if (x > 0)
		sum += x;
	if (y > 0)
		sum += y;
	if (z > 0)
		sum += z;
	cout << sum << '\n';
	return 0;
}