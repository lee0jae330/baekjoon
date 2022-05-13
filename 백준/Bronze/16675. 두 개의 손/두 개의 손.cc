#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	char m1, m2, t1, t2;
	cin >> m1 >> m2 >> t1 >> t2;
	int m=0, t=0;
	if (t1 == t2) {
		if (t1 == 'R' && (m1 == 'P' || m2 == 'P')) 
			m = 1;
		else if (t1 == 'S' && (m1 == 'R' || m2 == 'R'))
			m = 1;
		else if (t1=='P'&&(m1=='S'||m2=='S')) {
			m = 1;
		}
	}

	if (m1 == m2) {
		if (m1 == 'R' && (t1 == 'P' || t2 == 'P'))
			t = 1;
		else if (m1 == 'S' && (t1 == 'R' || t2 == 'R'))
			t = 1;
		else if(m1=='P'&&(t1=='S'||t2=='S'))
			t = 1;
	}
	if (!m && !t)
		cout << '?' << '\n';
	else if (m)
		cout << "MS" << '\n';
	else
		cout << "TK" << '\n';
	return 0;
}