#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<stack>

using namespace std;

vector<pair<int,int>>v;

int pre[100001];
vector<int>idx;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	fill(pre, pre+100001,-1);

	int N;
	cin >> N;
	v.resize(N);

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		v[i] = {x,-y};
	}

	sort(v.begin(), v.end());
	
	vector<int>lis;

	for (int i = 0; i < N; i++) {
		auto iter = upper_bound(lis.begin(), lis.end(), v[i].second);
		if (iter == lis.end()) {
			if (!lis.empty()) {
				pre[i] = idx[idx.size() -1];
			}
			lis.push_back(v[i].second);
			idx.push_back(i);
		}
		else {
			if (iter != lis.begin()) {
				pre[i] = idx[iter - lis.begin() -1];
			}
			*iter = v[i].second;
			idx[iter - lis.begin()] = i;
		}
	}

	cout << lis.size() <<'\n';

	int tmp = idx[idx.size() -1];
	stack<int>s;
	while (tmp != -1) {
		s.push(tmp);
		tmp = pre[tmp];
	}

	while (!s.empty()) {
		cout << v[s.top()].first <<' ' << -v[s.top()].second << '\n';
		s.pop();
	}
	return 0;
}