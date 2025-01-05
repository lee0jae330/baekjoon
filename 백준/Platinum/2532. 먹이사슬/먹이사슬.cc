#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

set<pair<int,int>>s;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num, L, R;
		cin >> num >> L >> R;
		s.insert({L,R});
	}
	
	vector<pair<int, int>>arr(s.begin(), s.end());
	sort(arr.begin(), arr.end(), compare);

	vector<int>v;
	for (auto [x, y] : arr) {
		v.push_back(-y);
	}

	vector<int>lis;
	for (int x : v) {
		auto iter = upper_bound(lis.begin(), lis.end(), x);
		if (iter == lis.end()) {
			lis.push_back(x);
		}
		else {
			*iter = x;
		}
	}

	cout << lis.size() << '\n';
	return 0;

}