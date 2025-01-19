#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

typedef long long ll;

int N, M;
vector<int>v;

bool determine(ll k) {
	ll cnt = 1;
	ll tmp = k;
	for (ll n : v) {
		if (tmp >= n) {
			tmp -= n;
		}
		else {
			cnt++;
			tmp = k;
			if (tmp < n) {
				return false;
			}
			tmp -= n;
		}
	}

	if (cnt <= M) {
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

	cin >> N >> M;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	ll sum = accumulate(v.begin(), v.end(), 0ll);
	cout << search(sum) << '\n';
	return 0;
}
