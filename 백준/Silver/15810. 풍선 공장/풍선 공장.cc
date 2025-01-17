#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int N, M;
vector<int>v;

bool canMade(ll t) {
	ll cnt = 0;
	for (int n : v) {
		cnt += t / n;
		if (cnt >= M) {
			return true;
		}
	}
	return false;
}

ll search() {
	ll left = 1ll;
	ll right = (ll)1e12;
	ll result = 0ll;
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (canMade(mid)) {
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
	cout << search() <<'\n';;
}