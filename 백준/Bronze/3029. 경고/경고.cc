#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


int main(void) {
	fastio();
	string s1, s2;
	cin >> s1 >> s2;
	
	int h1 = stoi(s1.substr(0, 2)), m1= stoi(s1.substr(3,2)),sec1=stoi(s1.substr(6,2));
	int h2 = stoi(s2.substr(0, 2)), m2 = stoi(s2.substr(3, 2)), sec2 = stoi(s2.substr(6, 2));

	h2 -= h1, m2 -= m1, sec2 -= sec1;
	if (h2 < 0)
		h2 += 24;
	if (h2 == 0 && m2 < 0)
		h2 += 24;
	if (h2 == 0 && m2 == 0 && sec2 < 0)
		h2 += 24;
	int time = h2 * 60 * 60 + m2 * 60 + sec2;
	h2 = time / 3600;
	time %= 3600;
	m2 = time / 60;
	sec2 = time %= 60;
	if (!h2 && !m2 && !sec2) {
		h2 = 24;
	}
	if (h2 < 10)
		cout << 0;
	cout << h2 << ':';
	if (m2 < 10)
		cout << 0;
	cout << m2 << ':';
	if (sec2 < 10)
		cout << 0;
	cout << sec2 << '\n';
	return 0;
}