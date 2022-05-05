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
	double M, S, G, A, B,L,R;
	cin >> M >> S >> G;
	cin >> A >> B;
	cin >> L >> R;
	double t1 = M / G + 1. / A * L, t2 = M / S + 1. / B * R;
	if (t1 < t2) {
		cout << "friskus";
	}
	else
		cout << "latmask";
	return 0;
}