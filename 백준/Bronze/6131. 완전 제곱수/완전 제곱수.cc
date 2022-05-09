#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


int main(void) {
	fastio();
	int N,cnt=0;
	cin >> N;
	for (int a = 1; a <= 500; a++) {
		for (int b = 1; b <= 500; b++) {
			if (a * a == b * b + N)
				cnt++;
		}
	}
	cout << cnt << '\n';
	return 0;
}