#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N , M;
	cin >> N >> M;
	string s;
	cin >> s;
	string sol ="";
	for (int i = s.length() - 1; i >= 0; i--) {
		if (sol.length() ==  0) {
			if (s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U') {
				sol.push_back(s[i]);
			}
		}
		else if (sol.length() == 1 || sol.length() == 2) {
			if (s[i] == 'A') {
				sol.push_back(s[i]);
			}
		}
		else if(sol.length() < M) {
			sol.push_back(s[i]);
		}
	}
	if (sol.length() == M) {
		cout << "YES" << '\n';
		reverse(sol.begin(), sol.end());
		cout << sol <<'\n';
	}
	else {
		cout << "NO" << '\n';
	}
	return 0;
}