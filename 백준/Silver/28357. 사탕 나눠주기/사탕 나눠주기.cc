#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

ll N, K;
vector<ll>v;

bool determine(ll score) {
	ll cnt = 0;
	for (ll n : v) {
		cnt += max(n - score, 0ll);
	}
	
	if (cnt <= K) {
		return true;
	}
	return false;
}

ll search(ll right) {
	ll left = 0;
	ll result = right;
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (determine(mid)) {
			result = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> K;
	v.resize(N);
	ll mx = -1;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		mx = max(mx, v[i]);
	}
	cout << search(mx) <<'\n';
	return 0;
}