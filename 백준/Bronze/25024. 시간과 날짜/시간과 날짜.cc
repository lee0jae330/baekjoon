#include<iostream>
#include<cmath>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int T;
	cin >> T;
	while (T--) {
		int x, y;
		cin >> x >> y;
		int f1 = 0, f2 = 0;
		if ((x >= 0 && x <= 23) && (y >= 0 && y <= 59))
			f1 = 1;
		if (x >= 1 && x <= 12) {
			if (x == 2) {
				if(y>=1&&y<=29)
					f2 = 1;
			}
			else if (x == 4 || x == 6 || x == 9 || x == 11) {
				if (y >= 1 && y <= 30)
					f2 = 1;
			}
			else {
				if (y >= 1 && y <= 31)
					f2 = 1;
			}
		}
		if (f1)
			cout << "Yes" << ' ';
		else
			cout << "No" << ' ';
		if (f2)
			cout << "Yes" << '\n';
		else
			cout << "No" << '\n';
	}
	return 0;
}