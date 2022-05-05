#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


int main(void) {
	fastio();
	int A, P;
	cin >> A >> P;
	A *= 7, P *= 13;
	if (A > P)
		cout << "Axel" << '\n';
	else if (A < P)
		cout << "Petra" << '\n';
	else
		cout << "lika" << '\n';
	return 0;
}