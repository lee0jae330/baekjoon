#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

typedef long long ll;

int N;
vector<pair<ll, ll>>v;

bool canHeat(ll time) {
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			auto [x1, y1] = v[i];
			ll s1, e1;
			if (y1 > 2 * time) {
				s1 = x1 - time;
				e1 = x1 + time;
			}
			else {
				s1 = x1 - (y1 / 2);
				e1 = x1 + (y1 / 2);
			}

			auto [x2, y2] = v[i + 1];
			ll s2, e2;
			if (y2 > 2 * time) {
				s2 = x2 - time;
				e2 = x2 + time;
			}
			else {
				s2 = x2 - (y2 / 2);
				e2 = x2 + (y2 / 2);
			}

			if (s2 <= e1) {
				return false;
			}
		}
		else if (i == N - 1) {
			auto [x1, y1] = v[i - 1];
			ll s1, e1;
			if (y1 > 2 * time) {
				s1 = x1 - time;
				e1 = x1 + time;
			}
			else {
				s1 = x1 - (y1 / 2);
				e1 = x1 + (y1 / 2);
			}

			auto [x2, y2] = v[i];
			ll s2, e2;
			if (y2 > 2 * time) {
				s2 = x2 - time;
				e2 = x2 + time;
			}
			else {
				s2 = x2 - (y2 / 2);
				e2 = x2 + (y2 / 2);
			}

			if (s2 <= e1) {
				return false;
			}
		}
		else {
			auto [x1, y1] = v[i];
			ll s1, e1;
			if (y1 > 2 * time) {
				s1 = x1 - time;
				e1 = x1 + time;
			}
			else {
				s1 = x1 - (y1 / 2);
				e1 = x1 + (y1 / 2);
			}

			auto [x2, y2] = v[i + 1];
			ll s2, e2;
			if (y2 > 2 * time) {
				s2 = x2 - time;
				e2 = x2 + time;
			}
			else {
				s2 = x2 - (y2 / 2);
				e2 = x2 + (y2 / 2);
			}

			if (s2 <= e1) {
				return false;
			}

			auto [x3, y3] = v[i - 1];
			ll s3, e3;
			if (y3 > 2 * time) {
				s3 = x3 - time;
				e3 = x3 + time;
			}
			else {
				s3 = x3 - (y3 / 2);
				e3 = x3 + (y3 / 2);
			}

			if (s1 <= e3) {
				return false;
			}
		}
	}
	return true;
}

ll search() {
	ll left = 0;
	ll right = (ll)1e9;
	ll result = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (canHeat(mid)) {
			result = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
	
	ll sol = search();
	if (sol == (ll)1e9) {
		cout << "forever" <<'\n';
	} else {
		cout << sol <<'\n';
	}
	return 0;
}