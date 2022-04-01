#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


int main(void) {
	fastio();

	int N;
	cin >>N;
	unsigned long long result =0;
	for (int i = 1; i <= N; i++) {
		result+=(N/i)*i;
	}
	cout <<result <<'\n';
	return 0;
}