#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int N;
vector<int>v;

bool determine(ll t) {
	for (int i = 0; i < N; i++) {
		if ((ll)(i+1) * t > v[i]) {
			return false;
		}
	}
	return true;
}

ll search(int mx) {
	ll left = 1;
	ll right = mx;
	ll result = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (determine(mid)) {
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

	int mx = 0;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		mx = max(mx, v[i]);
	}
	sort(v.begin(), v.end());
	cout << search(mx) << '\n';
	return 0;
}