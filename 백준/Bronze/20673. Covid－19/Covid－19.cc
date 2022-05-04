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
	int x, y;
	cin >> x >> y;
	if (x <= 50 && y <= 10) {
		cout << "White" << '\n';
	}
	else if (y > 30)
		cout << "Red" << '\n';
	else {
		cout << "Yellow" << '\n';
	}
	return 0;

}