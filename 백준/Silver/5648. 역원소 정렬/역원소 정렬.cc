#include<bits/stdc++.h>

using namespace std;

vector<long long> v;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	while (N--) {
		string s;
		cin >> s;
		reverse(s.begin(),s.end());
		v.push_back(stoll(s));
	}
	sort(v.begin(),v.end());
	for (long long num : v) {
		cout << num << '\n';
	}
	return 0;
}