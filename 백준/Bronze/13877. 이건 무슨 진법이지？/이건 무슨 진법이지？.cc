#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int T;
	cin >> T;
	while (T--) {
		int K;
		string s;
		cin >> K >> s;
		string tmp = s;
		long long oct=0, dec=0, hex=0;
		reverse(s.begin(), s.end());
		for (int i = 0; i < s.length(); i++) {
			if (s[i] >= '8') {
				oct = 0;
				break;
			}
			oct += pow(8, i) * (s[i] - '0');
		}
		dec = stol(tmp);
		for (int i = 0; i < s.length(); i++) {
			hex += pow(16, i) * (s[i] - '0');
		}
		cout << K << ' ' << oct << ' ' << dec << ' ' << hex << '\n';
	}
	return 0;
}