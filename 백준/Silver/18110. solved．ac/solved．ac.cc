#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

vector<double>v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	double N;
	cin >> N;

	if (!N) {
		cout << 0;
		return 0;
	}

	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	double x = N * 0.15;
	x = round(x);

	double score = 0;
	int n = 0;
	for (int i = x; i < N - x; i++) {
		score+=v[i];
		n++;
	}
	
	cout << round(score/n)<<'\n';
	return 0;
}
