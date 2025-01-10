#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, K;
	cin >> N >> K;
	string str;
	cin >> str;

	int x = 0, y = 0;
	for (int i = 0; i < min(N, K); i++) {
		for (char c : str) {
			if (c == 'U') {
				y++;
			}
			else if (c == 'D') {
				y--;
			}
			else if (c == 'L') {
				x--;
			}
			else {
				x++;
			}

			if (!x && !y) {
				cout << "YES" << '\n';
				return 0;
			}
		}
	}
	cout << "NO" << '\n';
	return 0;
}