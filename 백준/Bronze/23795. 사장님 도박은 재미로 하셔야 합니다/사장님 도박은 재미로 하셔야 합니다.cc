#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int result = 0;
	while (1) {
		int num;
		cin >> num;
		if (num == -1)
			break;
		result += num;
	}
	cout << result << '\n';
	return 0;
}