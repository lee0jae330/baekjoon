#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

const int SIZE = 1e6 + 1;
int arr[SIZE];
int pre[SIZE];
vector<int>lis;
vector<int>idx;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		auto iter = lower_bound(lis.begin(), lis.end(), arr[i]);
		if (iter == lis.end()) {
			if (lis.size() == 0) {
				pre[i] = -1;
			}
			else {
				pre[i] = idx[idx.size() -1];
			}
			lis.push_back(arr[i]);
			idx.push_back(i);
			
		}
		else {
			if (iter - lis.begin() == 0) {
				pre[i] = -1;
			}
			else {
				pre[i] = idx[iter-lis.begin()-1];
			}
			*iter = arr[i];
			idx[iter -lis.begin()] = i;
		}
	}
	
	stack<int>s;
	int tmp = idx[idx.size()-1];

	while (tmp != -1) {
		s.push(tmp);
		tmp = pre[tmp];
	}

	cout << lis.size() <<'\n';
	while (!s.empty()) {
		cout << arr[s.top()] << ' ';
		s.pop();
	}
	return 0;
}
