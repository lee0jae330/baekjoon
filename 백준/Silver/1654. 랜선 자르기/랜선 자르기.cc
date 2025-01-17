#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

vector<ll>v;

bool cmp(ll length, ll num) {
	ll cnt = 0;
	for (ll n : v) {
		cnt += n /length;
		if (num <= cnt) {
			return true;
		}
	}
	return false;
}

ll search(ll num) {
	ll left = 1;
	ll right = v[v.size()-1];
	ll result = 0;
	while (left <= right) {
		ll mid = (left + right)/ 2;
		if (cmp(mid, num)) {
			result = mid;
			left = mid+1;
		}
		else {
			right = mid-1;
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ll K, N;
	cin >> K >> N;
	v.resize(K);
	for (ll i = 0; i < K; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	cout << search(N) <<'\n';
	return 0;
}