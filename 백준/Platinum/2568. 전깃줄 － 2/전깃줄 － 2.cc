#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<utility>

using namespace std;

map<pair<int,int>,pair<int,int>>m;
vector<pair<int,int>>v;
vector<int>lis;

int pre[100001];
vector<int>idx;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int x,y; 
		cin >>x >> y;
		m[{x,y}] = {x,0};
		v.push_back({x,y});
	}

	sort(v.begin(), v.end());

	

	for (int i = 0; i < N; i++) {
		auto iter = lower_bound(lis.begin(), lis.end(),v[i].second);
		if (iter == lis.end()) {
			if (lis.size() == 0) {
				pre[i] = -1;
			}
			else {
				pre[i] = idx[idx.size() -1];
			}
			lis.push_back(v[i].second);
			idx.push_back(i);
		}
		else {
			if (iter == lis.begin()) {
				pre[i] = -1;
			}
			else {
				pre[i] = idx[iter - lis.begin() - 1];
			}
			*iter = v[i].second;
			idx[iter - lis.begin()] = i;
		}
	}

	stack<int>s;
	int tmp = idx[idx.size()-1];
	while (tmp != -1) {
		s.push(tmp);
		tmp = pre[tmp];
	}

	while (!s.empty()) {
		int num = s.top();
		s.pop();
		m[v[num]].second = 1;
	}

	cout << N - lis.size() <<'\n';

	set<int>sol;
	for (auto iter : m) {
		if (!iter.second.second) {
			sol.insert(iter.second.first);
		}
	}
	for (int num : sol) {
		cout << num <<'\n';
	}
	return 0;
}