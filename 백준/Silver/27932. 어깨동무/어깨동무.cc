#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;


typedef long long ll;
vector<ll>v;
ll N, K;

bool determine(ll length) {
	
	ll cnt = 0;
	for (ll i = 0; i < N; i++) {
		if (i == 0) {
			if (abs(v[i + 1] - v[i]) > length) {
				cnt++;
			}
		}
		else if (i == N - 1) {
			if (abs(v[i - 1] - v[i]) > length) {
				cnt++;
			}
		}
		else {
			if (abs(v[i] - v[i - 1]) > length || abs(v[i + 1] - v[i]) > length) {
				cnt++;
			}
		}

	}
	if (cnt <= K) {
		return true;
	}
	return false;
}

ll search(ll right) {
	ll left = 0;
	ll result =0;
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
	for (ll i = 0; i < N; i++) {
		cin >> v[i];
		mx = max(mx, v[i]);
	}
	if (N == 1) {
		cout << 0 <<'\n';
		return 0;
	}
	cout << search(mx) <<'\n';
	return 0;
}