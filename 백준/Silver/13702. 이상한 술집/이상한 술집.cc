#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

vector<int>v;
int N, K;

bool canDivide(ll num) {
	ll cnt =0;
	for (int n : v) {
		cnt += n / num;
		if (cnt >= K) {
			return true;
		}
	}
	return false;
}

ll search() {
	ll left = 1;
	ll right = v[N-1];
	ll result =0;
	while (left <= right) {
		ll mid = (left + right) /2;
		if (canDivide(mid)) {
			result = mid;
			left = mid+1;
		}
		else {
			right = mid -1 ;
		}
	}
	return result;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	cout << search() <<'\n';
	return 0;
}