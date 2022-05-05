#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


int main(void) {
	fastio();
	int t1, m1, t2, m2;
	cin >> t1 >> m1 >> t2 >> m2;
	t2 -= t1;
	m2 -= m1;
	if (t2 < 0)
		t2 += 24;
	if (!t2 && m2 < 0)
		t2 += 24;
	int sum = t2 * 60 + m2;
	cout << sum << ' ' << sum / 30 << '\n';
	return 0;
}