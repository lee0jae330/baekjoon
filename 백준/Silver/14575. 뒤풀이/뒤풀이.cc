#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;
int N, T;
vector<pair<int, int>>v;

bool determine(ll num) {
	ll mn = 0, mx = 0;
	for (auto [x, y] : v) {
		if (num < x) {
			return false;
		}
		mn += x;
		mx += min((ll)y, num);
	}
	if (mn <= T && T <= mx) {
		return true;
	}
	return false;
}

ll search(ll right) {
	ll left = 1;
	ll result = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (determine(mid)) {
			result = mid;
			right = mid -1;
		}
		else {
			left = mid +1;
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> T;
	v.resize(N);
	ll mx = 0;
	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
		mx = max(mx, (ll)max(v[i].first, v[i].second));
	}
	ll sol = search(mx);
	cout << ((sol == 0) ? -1 : sol) << '\n';
	return 0;
}