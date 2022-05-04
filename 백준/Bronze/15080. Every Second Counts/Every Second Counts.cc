#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int a, b, c;
	char c1, c2;
	cin >> a >> c1 >> b >> c2 >> c;
	int x, y, z;
	cin >> x >> c1 >> y >> c2 >> z;
	int h = x - a, m = y - b, s = z - c;
	if (h < 0)
		h += 24;
	if (h == 0 && m < 0)
		h += 24;
	if (h == 0 && m == 0 && s < 0)
		h += 24;
	if (!h && !m && !s)
		h += 24;
	cout << h * 3600 + 60 * m + s << '\n';
	return 0;
}