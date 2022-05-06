#include<iostream>
#include<cmath>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


int main(void) {
	int t1, v1,t2,v2;
	cin >> t1 >> v1 >> t2 >> v2;

	if (t2 < 0 && v2 >= 10)
		cout << "A storm warning for tomorrow! Be careful and stay home if possible!" << '\n';
	else if (t1 > t2)
		cout << "MCHS warns! Low temperature is expected tomorrow." << '\n';
	else if (t1<=t2&&v1 < v2)
		cout << "MCHS warns! Strong wind is expected tomorrow." << '\n';
	else
		cout << "No message" << '\n';
	
	return 0;
}