#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


int main(void) {
	fastio();
	for (int a = 2; a <= 100; a++) {

		for (int b = 2; b <= 100; b++) {
			for (int c = 2; c <= 100; c++) {
				if (b > c)
					continue;
				for (int d = 2; d <= 100; d++) {
					if (c > d)
						continue;
					if (a * a * a == b * b * b + c * c * c + d * d * d) 
						cout << "Cube = " << a << ", Triple = (" << b << ',' << c << ',' << d << ')' << '\n';
					else if (a * a * a < b * b * b + c * c * c + d * d * d)
						break;
				}
			}
		}

	}

	return 0;
}