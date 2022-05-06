#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


int main(void) {
	int a, x, b, y,T;
	cin >> a >> x >> b >> y >> T;
	int cost = a;
	if (T - 30 > 0)
		cost += (T - 30) * x * 21;
	cout << cost << ' ';
	cost = b;
	if (T - 45 > 0)
		cost += (T - 45) * y * 21;
	cout << cost << '\n';
	return 0;
}