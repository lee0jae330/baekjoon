#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int N, A, B;
	cin >> N >> A >> B;
	int a = N - A, b= N-B;
	a = max(a, A);
	b = max(b, B);
	cout << 4 * a * b << '\n';
	
	return 0;
}