#include<iostream>


using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


int main(void) {
	long long a, b;
	cin >> a >> b;
	long long result = 0;
	if (b > 0) {
		result++;
		b--;
		if (b < a)
			result += b;
		else if (b > a)
			result += a;
		else
			result += b;
	}
	cout << result << '\n';
	return 0;
}