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
	int a, b,s1=0,s2=0,away1, away2;
	cin >> a >> b;
	s1 = a, s2 = b;
	away1 = b; //est
	cin >> a >> b;
	s1 += b, s2 += a;
	away2 = b; //per
	if (s1 > s2) {
		cout << "Persepolis" << '\n';
	}
	else if (s1 < s2) {
		cout << "Esteghlal" << '\n';
	}
	else {
		if (away1 > away2)
			cout << "Esteghlal" << '\n';
		else if (away1 < away2)
			cout << "Persepolis" << '\n';
		else
			cout << "Penalty" << '\n';
	}
	return 0;
}