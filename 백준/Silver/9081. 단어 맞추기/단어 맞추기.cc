#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<char>v;

int main(void) {
	int T;
	cin >> T;
	while (T--) {
		v.clear();
		string s;
		cin >> s;
		for (int i = 0; i < s.length();i++)
			v.push_back(s[i]);
		if (next_permutation(v.begin(), v.end())) {
			for (int i = 0; i < v.size(); i++)
				cout << v[i];
		}
		else
			cout << s;
		cout << '\n';
	}
	return 0;
}