#include<bits/stdc++.h>

using namespace std;

vector<string>v;
vector<long long>numbers;

string rev(string& s) {
	string tmp;
	int flag = 0;
	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] == '0') {
			if (!flag) {
				continue;
			}
			else {
				tmp.push_back(s[i]);
			}
		}
		else {
			flag = 1;
			tmp.push_back(s[i]);
		}
	}
	if (tmp.empty()) {
		tmp.push_back('0');
	}
	return tmp;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	while (N--) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	for (string s : v) {
		numbers.push_back(stoll(rev(s)));
	}
	sort(numbers.begin(),numbers.end());
	for (long long num : numbers) {
		cout << num <<'\n';
	}
	return 0;
}