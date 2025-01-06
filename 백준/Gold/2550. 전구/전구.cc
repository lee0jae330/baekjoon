#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<utility>

using namespace std;

map<int, int>sw;
map<int, int>light;
int arr[10001];

vector<pair<int, int>>v;

int pre[10001];
vector<int>idx;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	fill(pre, pre + 10001, -1);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sw[arr[i]] = i;
	}
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		light[num] = i;
	}

	for (int i = 1; i <= N; i++) {
		v.push_back({ sw[i], light[i] });
	}

	sort(v.begin(), v.end());
	vector<int>lis;
	for (int i = 0; i < N; i++) {
		auto iter = lower_bound(lis.begin(), lis.end(), v[i].second);
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
			*iter =v[i].second;
			idx[iter - lis.begin()] = i;
		}
	}

	cout << lis.size() <<'\n';
	
	int tmp = idx[idx.size() -1];
	vector<int>sol;
	while (tmp != -1) {
		sol.push_back(arr[tmp]);
		tmp =pre[tmp];
	}

	sort(sol.begin(), sol.end());
	
	for (int i : sol) {
		cout << i << ' ';
	}
	cout <<'\n';
	return 0;

}