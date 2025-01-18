#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

int N, M;
vector<int>v;

bool determine(ll num) {
	ll cnt = 0;
	for (int n : v) {
		cnt += (n / num);
		if (n % num) {
			cnt++;
		}
	}
	if (cnt <= N) {
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
			right = mid-1;
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
	cin >> N >> M;
	v.resize(M);

	ll mx = 0;

	for (int i = 0; i < M; i++) {
		cin >> v[i];
		mx = max(mx, (ll)v[i]);
	}
	cout << search(mx) <<'\n';
	return 0;
}