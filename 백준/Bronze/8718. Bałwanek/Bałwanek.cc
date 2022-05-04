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
	long long x,k;
	cin >> x >> k;
	x *= 1000;
	k *= 1000;
	long long result = 0;
	if (k / 4 + k / 2 + k <= x)
		result = k / 4 + k / 2 + k;
	if (k / 2 + k + 2 * k <= x)
		result = k / 2 + k + 2 * k;
	if (k + 2 * k + 4 * k <= x)
		result = k + 2 * k + 4 * k;
	
	cout << result << '\n';

	return 0;
}