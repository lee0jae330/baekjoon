#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int A,B,C;
	cin >> A >> B >> C;
	cout << A + B - C <<'\n';
	if(B < 10)
		cout << A * 10 + B -C <<'\n';
	else if(B< 100) {
		cout << A * 100 + B - C <<'\n';
	}
	else if (B < 1000) {
		cout << A * 1000 + B - C<<'\n';
	}
	else {
		cout << A * 10000 + B - C<<'\n';
	}

	return 0;
}