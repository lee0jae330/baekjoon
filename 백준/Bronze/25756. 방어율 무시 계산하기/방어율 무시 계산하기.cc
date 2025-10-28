#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	
	vector<double>v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		v[i] = v[i] * 0.01;
	}

	double V = 0.0;
	cout.precision(6);
	cout << fixed;
	for (double n : v) {
		V = 1 - (1 - V) * (1 - n);
		cout << V * 100 << '\n';
	}
	return 0;
}