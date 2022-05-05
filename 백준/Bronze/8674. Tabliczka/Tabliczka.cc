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
	long long a, b;
	cin >> a >> b;
	if (a % 2 == 0 || b % 2 == 0)
		cout << 0;
	else
		cout << min(a, b);
	return 0;
}