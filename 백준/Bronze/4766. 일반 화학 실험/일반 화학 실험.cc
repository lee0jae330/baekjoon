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
	int flag = 0;
	double a, b;
	while (1) {
		if (!flag) {
			flag = 1;
			cin >> a;
		}
		else {
			cin >> b;
			if (b == 999)
				break;
			cout << fixed;
			cout.precision(2);
			cout << b-a<<'\n';
			a = b;

		}
	}
	return 0;
}