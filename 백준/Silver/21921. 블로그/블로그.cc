#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

int X, N;

vector<int>v;
vector<ll>sol;

bool comp(const int& a, const int& b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> X;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	ll sum = 0;
	for (int i = 0; i < X; i++) {
		sum += v[i];
	}

	sol.push_back(sum);
	for (int i = 1; i <= N - X; i++) {
		sum -= v[i - 1];
		sum += v[i + X -1];
		sol.push_back(sum);
	}
	
	sort(sol.begin(), sol.end(), comp);

	if (!sol[0]) {
		cout << "SAD" << '\n';
		return 0;
	}

	cout << sol[0] << '\n';
	int cnt = 1;
	for (int i = 1; i < sol.size(); i++) {
		if (sol[i] == sol[0]) {
			cnt++;
		}
		else {
			break;
		}
	}
	cout << cnt << '\n';
	return 0;
}