#include<iostream>
#include<string>

using namespace std;

int main() {
	int N;
	cin >> N;
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	string str;
	cin >> str;
	if (str[0] != 'a' || str[N - 1] != 'a') {
		cout << "No" << '\n';
		return 0;
	}
	int a = 0, b = 0, c = 0, d = 0;
	for (int i = 0; i < N; i++) {
		switch (str[i]) {
		case 'a':
			a++;
			break;
		case 'b':
			b++;
			break;
		case 'c':
			c++;
			break;
		default:
			d++;
		}
		if (i < N - 1) {
			if (str[i] == str[i + 1]) {
				cout << "No" <<'\n';
				return 0;
			}
		}
	}

	if (a <= A && b <= B && c <= C && d <= D) {
		cout << "Yes" <<'\n';
	}
	else {
		cout << "No" <<'\n';
	}
	return 0;
}