#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<stack>

using namespace std;

vector<int>arr;
vector<int>lis;
vector<int>idx;
int pre[200001];
int visited[200001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	arr.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}


	for (int i = 0; i < N; i++) {
		auto iter = upper_bound(lis.begin(), lis.end(), arr[i]);
		if (iter == lis.end()) {
			if (lis.size() == 0) {
				pre[i] = -1;
			}
			else {
				pre[i] = idx[idx.size() - 1];
			}
			lis.push_back(arr[i]);
			idx.push_back(i);
		}
		else {
			if (iter == lis.begin()) {
				pre[i] = -1;
			}
			else {
				pre[i] = idx[iter - lis.begin() - 1];
			}
			*iter = arr[i];
			idx[iter - lis.begin()] = i;
		}
	}

	if (N - lis.size() > 3) {
		cout << "NO" << '\n';
		return 0;
	}

	vector<int>tmp = arr;
	sort(tmp.begin(), tmp.end());

	cout << "YES" << '\n';
	if (tmp == arr) {
		return 0;
	}


	stack<int>s;
	int num = idx[idx.size() -1];
	while (num != -1) {
		s.push(num);
		num = pre[num];
	}

	while (!s.empty()) {
		int index = s.top();
		s.pop();
		visited[index] = 1;
	}

	vector<pair<int, int>>v;

	for (int i = 0; i < N; i++) {
		if (visited[i]) {
			continue;
		}
		int flag =0;
		for (int j = i + 1; j < N; j++) {
			if (visited[j]) {
				arr[i] = arr[j];
				v.push_back({i+1, arr[j]});
				flag=1;
				break;
			}
		}
		if (!flag) {
			for (int j = i - 1; j >= 0; j--) {
				if (visited[j]) {
					arr[i] = arr[j];
					v.push_back({ i + 1, arr[j] });
					break;
				}
			}
		}
	}
	cout << v.size() << '\n';
	for (auto [x, y] : v) {
		cout << x << ' ' << y << '\n';
	}
}