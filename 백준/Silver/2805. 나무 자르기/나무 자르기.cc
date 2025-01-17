#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

int N, M;
vector<int>v;

bool cmp(int length) {
	ll sum = 0;
	for (int n : v) {
		sum += max(0, n - length);
		if (sum >= M) {
			return true;
		}
	}
	return false;
}

ll search() {
	ll left = 0;
	ll right = v[N - 1];
	ll result = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (cmp(mid)) {
			result = mid;
			left =mid+1;
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
	cin >> N >> M;
	v.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	cout << search() <<'\n';
	return 0;
}