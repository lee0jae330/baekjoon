#include<iostream>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	cin >> str;
	int year = stoi(str.substr(0, 4));
	int month = stoi(str.substr(5, 7));
	int day = stoi(str.substr(8));

	int N;
	cin >> N;
	int cnt = 0;
	while (N--) {
		string tmp;
		cin >> tmp;
		int y = stoi(tmp.substr(0, 4));
		int m = stoi(tmp.substr(5, 7));
		int d = stoi(tmp.substr(8));

		if (y > year) {
			cnt++;
			continue;
		}

		if (y == year) {
			if (m > month) {
				cnt++;
				continue;
			}

			if (m == month) {
				if (d >= day) {
					cnt++;
				}
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}