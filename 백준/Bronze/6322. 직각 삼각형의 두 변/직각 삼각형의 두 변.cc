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
	int T = 1;
	cout << fixed;
	cout.precision(3);
	while (1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (!a && !b && !c)
			break;
		cout << "Triangle #" << T++ << '\n';
		
		if (a == -1) {
			if (b < c) {
				cout << "a = " << sqrt((double)pow(c, 2) - (double)pow(b, 2))<<'\n';
			}
			else {
				cout << "Impossible." << '\n';
			}
		}
		else if (b == -1) {
			if (a < c) {
				cout << "b = " << sqrt((double)pow(c, 2) - (double)pow(a, 2)) << '\n';
			}
			else
				cout << "Impossible." << '\n';

		}
		else {
			cout << "c = " << sqrt((double)pow(a, 2) + (double)pow(b, 2)) << '\n';
		}
		cout << '\n';
	}
	return 0;
}