#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int S, M, L;
	cin >> S >> M >> L;
	if (S + 2 * M + 3 * L >= 10)
		cout << "happy" << '\n';
	else
		cout << "sad" << '\n';
	return 0;
}