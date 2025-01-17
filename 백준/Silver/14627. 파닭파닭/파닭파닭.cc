#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int S, C;
vector<int>v;

bool canDivide(ll length) {
	ll cnt = 0;
	for (int n : v) {
		cnt += n / length;
		if (cnt >= C) {
			return true;
		}
	}
	return false;
}

ll search() {
	ll left = 1;
	ll right = *max_element(v.begin(), v.end());
	ll result =0;
	while (left <= right) {
		ll mid = (left + right) /2;
		if (canDivide(mid)) {
			result = mid;
			left = mid+1;
		} else{
			right  = mid -1;
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> S >> C;
	v.resize(S);
	for (int i = 0; i < S; i++) {
		cin >> v[i];
	}
	
	ll greenOnion =search();
	ll sum = 0;
	for (int n : v) {
		sum +=n;
	}
	
	cout << sum -  greenOnion * C <<'\n';
	return 0;
}