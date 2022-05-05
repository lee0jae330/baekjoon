#include<iostream>
#include<cmath>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


int main(void) {
	fastio();
	int N, K;
	cin >> N >> K;
	K += 60;
	int cost;
	if (K >= N) {
		cost = N * 1500;
	}
	else {
		cost = K * 1500;
		cost += (N - K) * 3000;
	}
	cout << cost << '\n';
	return 0;
}