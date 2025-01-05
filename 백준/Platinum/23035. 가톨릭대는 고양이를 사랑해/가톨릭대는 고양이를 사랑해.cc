#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

vector<pair<int,int>>v;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int x, y;
		cin >> x >> y;
		if (x <= N && y <= M) {
			v.push_back({x,y});
		}
	}

	sort(v.begin(), v.end());
	vector<int>lis;
	for (auto [x, y] : v) {
		auto iter = upper_bound(lis.begin(), lis.end(), y);
		if (iter == lis.end()) {
			lis.push_back(y);
		}
		else {
			*iter = y;
		}
	}
	cout << lis.size() << '\n';
	return 0;
}