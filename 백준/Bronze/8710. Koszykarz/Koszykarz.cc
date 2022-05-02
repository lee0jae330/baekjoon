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
	long long k,w,m;
	cin >> k >> w >> m;
	long long gap = w - k;
	int flag = 0;
	if (gap % m)
		flag = 1;
	cout << gap/m+flag << '\n';
	return 0;
}