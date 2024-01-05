#include<bits/stdc++.h>

using namespace std;

vector<long long>v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	for(int i=0;i<N;i++) {
		long long num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(),v.end());
	long long cur = v[0];
	long long mx_num = v[0];
	int mx_cnt = -1;
	int cnt =1;
	for (int i = 1; i < N; i++) {
		if (cur == v[i]) {
			cnt++;
		}
		else {
			if (mx_cnt < cnt) {
				mx_cnt = cnt;
				mx_num = cur;
			}
			cnt = 1;
			cur = v[i];
		}
	}
	if (cnt > mx_cnt) {
		mx_num = cur;
	}
	cout << mx_num <<'\n';
	return 0;
}