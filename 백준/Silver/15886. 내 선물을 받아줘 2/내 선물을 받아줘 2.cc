#include<iostream>
#include<string>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int N;
	cin >> N;
	string str;
	cin >> str;
	int cnt = 0;
	for (int i = 0; i < str.length() - 1; i++) {
		if (str[i] == 'E' && str[i + 1] == 'W') {
			cnt++;
		}
	}
	cout << cnt <<'\n';
	return 0;
}