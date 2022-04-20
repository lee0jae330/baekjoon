#include<iostream>
#include<set>
#include<string>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

set<char>s;
map<int, int> m;
vector<string>v;

int main(void) {
	fastio();
	int N;
	cin >> N;
	cin.ignore();
	for (int n = 0; n < N; n++) {
		string str;
		getline(cin, str);
		
		v.push_back(str);
		char ch = str[0];
		if (str[0] < 'a')
			ch += 32;
		if (s.find(ch) == s.end()) { //첫번째
			s.insert(ch);
			m.insert({ n,0});
		}
		else {
			int len = str.length();
			int flag = 0;
			for (int i = 0; i < len; i++) { //두번째
				if (str[i] == ' ') {
					char c = str[i + 1];
					if (c < 'a')
						c += 32;
					if (s.find(c) == s.end()) {
						s.insert(c);
						m.insert({ n,i+1 });
						flag = 1;
						break;
					}
				}
			}
			if (flag)
				continue;
			for (int i = 1; i < len; i++) {
				if (str[i] == ' ')
					continue;
				else {
					char tmp = str[i];
					if (tmp < 'a')
						tmp += 32;
					if (s.find(tmp) == s.end()) {
						s.insert(tmp);
						m.insert({ n,i });
						flag = 1;
						break;
					}
				}
			}
			if (flag)
				continue;
		}
	}
	for (int i = 0; i < N; i++) {
		if (m.find(i) == m.end())
			cout << v[i] << '\n';
		else {
			int num = m[i];
			for (int j = 0; j < v[i].length(); j++) {
				if (num == j) {
					cout << '[' << v[i][j] << ']';
				}
				else
					cout << v[i][j];
			}
			cout << '\n';
		}
	}
	return 0;
}