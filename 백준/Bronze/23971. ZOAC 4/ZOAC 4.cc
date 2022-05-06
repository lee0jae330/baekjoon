#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int H, W, N, M;
	cin >> H >> W >> N >> M;
	int n = H / (1 + N), m= W/(1+M);
	if (H % (1 + N) > 0)
		n++;
	if (W % (1 + M) > 0)
		m++;
	cout << n * m << '\n';

	return 0;
}