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
	int a, b;
	cin >> a >> b;
	cout << max(a + b, a - b) << '\n';
	cout << min(a + b, a - b) << '\n';
	return 0;

}