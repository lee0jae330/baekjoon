#include<iostream>
#include<vector>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<int>v;

int main(void) {
	fastio();
	int N,sum=0;
	cin >> N;
	for (int i = 0; i < N;i++) {
		int num;
		cin >> num;
		sum += num;
		v.push_back(num);
	}
	long long int result = 0;
	for (int i = 0; i < N - 1; i++) {
		result += v[i] * (sum - v[i]);
		sum -= v[i];
	}
	cout << result << '\n';
	return 0;
}