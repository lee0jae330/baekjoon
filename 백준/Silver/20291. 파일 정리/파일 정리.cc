#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

map<string, int > m;


int main(void) {
	fastio();
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		int idx = s.find(".");
		string s1 = s.substr(idx + 1, s.size());
		if (m.find(s1) != m.end()) {
			m[s1]++;
		}
		else
			m.insert({ s1,1 });
	}
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		cout << iter->first << " " << iter->second << "\n";
	}
	return 0;
}