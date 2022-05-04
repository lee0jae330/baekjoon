#include<iostream>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int A, B, C;
	cin >> A >> B >> C;
	if (A <= C && C < B)
		cout << 1 << '\n';
	else
		cout << 0 << '\n';
	return 0;

}