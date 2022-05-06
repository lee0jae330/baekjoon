#include<iostream>
#include<cmath>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


int main(void) {
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	if (A > C+1 && B > D+1)
		cout << 1 << '\n';
	else
		cout << 0 << '\n';
	return 0;
}