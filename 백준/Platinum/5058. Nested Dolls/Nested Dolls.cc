#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

vector<pair<int,int>>arr;


bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		arr.clear();
		int N;
		cin >> N;
		arr.resize(N);

		for (int i = 0; i < N; i++) {
			cin >> arr[i].first >> arr[i].second;
		}

		sort(arr.begin(), arr.end(), compare);

		int cnt = 0;
		vector<int>lis;
		vector<int>tmp;
		vector<int>v;
		while (1) {
			cnt++;
			lis.clear();
			v.clear();
			if (cnt == 1) {
				for (auto [x, y] : arr) {
					auto iter = lower_bound(lis.begin(), lis.end(), y);
					if (iter == lis.end()) {
						lis.push_back(y);
					}
					else {
						int num = *iter;
						tmp.push_back(num);
						*iter = y;
					}
				}
			}
			else {
				v = tmp;
				tmp.clear();
				for (int x : v) {
					auto iter = lower_bound(lis.begin(), lis.end(), x);
					if (iter == lis.end()) {
						lis.push_back(x);
					}
					else {
						int num = *iter;
						tmp.push_back(num);
						*iter = x;
					}
				}
			}
			//for (int num : lis) {
			//	cout << num << ' ';
			//}
			//cout << '\n';
			if (lis.size() == 1) {
				if (cnt == 1) {
					cnt = N;
				}
				else {
					cnt--;
					cnt += v.size();
				}
				break;
			}
			if (tmp.empty()) {
				break;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}