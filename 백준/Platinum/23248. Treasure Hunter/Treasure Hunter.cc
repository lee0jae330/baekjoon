#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

vector<pair<int,int>>v;
vector<int>lis;
vector<int>tmp;
vector<int>cp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int M,N,K;
	cin >> M >> N >> K;
	v.resize(K);
	for (int i = 0; i < K; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());

	int cnt = 0;
	
	while (1) {
		lis.clear();
		cp.clear();
		cnt++;
		if (cnt == 1) {
			for (auto [x, y] : v) {
				auto iter = upper_bound(lis.begin(), lis.end(), y);
				if (iter == lis.end()) {
					lis.push_back(y);
				}
				else {
					int pre = *iter;
					tmp.push_back(pre);
					*iter = y;
				}
			}
		}
		else {
			cp = tmp;
			tmp.clear();
			for (int x : cp) {
				auto iter= upper_bound(lis.begin(), lis.end(), x);
				if (iter == lis.end()) {
					lis.push_back(x);
				}
				else {
					int pre = *iter;
					tmp.push_back(pre);
					*iter = x;
				}
			}	
		}

		
	
		if (tmp.empty()) {
			break;
		}
	}
	cout << cnt <<'\n';
	return 0;
	
}
