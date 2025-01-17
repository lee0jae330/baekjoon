#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

int N, K, M;
vector<int>v;

bool canDivide(ll length) {
	ll cnt = 0;
	for (int n : v) {
		cnt += n / length;
		if (cnt >= M) {
			return true;
		}
	}
	return false;
}

ll search(ll right) {
	ll left = 1;
	ll result = -1;
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (canDivide(mid)) {
			result = mid;
			left = mid + 1;
		}
		else {
			right = mid -1;
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> K >> M;
	ll mx = -1;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		if (num <= K)
			continue;
		num = (num >= 2*K) ? num - 2*K : num - K;
		mx = max(mx, (ll)num);
		v.push_back(num);
	}
	cout << search(mx) <<'\n';
	return 0;
}