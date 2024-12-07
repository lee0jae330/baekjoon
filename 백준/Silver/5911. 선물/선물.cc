#include<iostream>
#include<algorithm>
#include<vector>

typedef long long ll;

using namespace std;

bool compare(pair<ll, ll>a, pair<ll, ll>b) {
	int sumA = a.first + a.second;
	int sumB = b.first + b.second;

	if (sumA == sumB) {
		return a.second < b.second;
	}

	return sumA < sumB;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, B;
	cin >> N >> B;
	
	vector<pair<ll, ll>>v(N);
	
	for (int i = 0; i < N; i++) {
		int p, s;
		cin >> p >> s;
		v[i] = { p,s };
	}

	sort(v.begin(), v.end(), compare);
	ll sol = -1;

	for (int x = 0; x < N; x++) {
		ll cnt = 0, total = 0;

		for (int i = 0; i < N; i++) {
			if (i == x) {
				if (total + v[i].first / 2 + v[i].second <= B) {
					cnt++;
					total += v[i].first / 2 + v[i].second;
				}
				else {
					break;
				}
			}
			else {
				if (total + v[i].first + v[i].second <= B) {
					cnt++;
					total += v[i].first+ v[i].second;
				}
				else {
					break;
				}
			}
		}
		sol = max(sol, cnt);
	}
	cout << sol << '\n';
	return 0;
}