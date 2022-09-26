#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<double>v;

int main(void) {
	fastio();
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		double num; cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	double sol1=0,sol2=0;
	for (int i = K; i < N - K; i++)
		sol1 += v[i];
	sol1 = sol1 / (N - 2 * K);
	for (int i = 0; i < K; i++) {
		sol2 += v[K];
		sol2 += v[N - K - 1];
	}
	for (int i = K; i < N - K; i++)
		sol2 += v[i];
	sol2 /= N;
	double s1 = sol1 * 100+0.5;
	double s2 = sol2 * 100 + 0.5;
	s1 = floor(s1), s2 = floor(s2);
	s1 /= 100;
	s2 /= 100;

	cout<<fixed;
	cout.precision(2);
	cout << s1 << '\n' << s2 << '\n';
	return 0;
}