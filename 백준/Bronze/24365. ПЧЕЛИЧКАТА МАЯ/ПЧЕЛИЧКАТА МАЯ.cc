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
	int x, y, z,result=0;
	cin >> x >> y >> z;
	int avg = (x + y + z) / 3;
	int m = min(x, y);
	m = min(m, z);

	if (m == x) {
		
		if (x < avg) {
			int tmp = avg - x;
			result += tmp;
			y -= tmp;
		}
		if (y < avg) {
			int tmp = avg - y;
			result += tmp;
		}
	}
	else if (m == y) {
		x -= avg;
		y -= avg;
		z -= avg;
		if (x > 0)
			result += x;
		if (z > 0)
			result += z;
	}
	else {
		if (z < avg) {
			result += (avg - z);
			y -= (avg - z);
		}
		if (y < avg)
			result += (avg - y);
	}
	cout << result << '\n';
	return 0;

}