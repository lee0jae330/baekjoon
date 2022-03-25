#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<string>v;

vector<int> Fail(string pattern) {
	int n = pattern.length();
	
	vector<int>pi(n);
	pi[0] = 0;
	for (int i = 1, j = 0; i < n; i++) {
		while (j > 0 && pattern[i] != pattern[j])
			j = pi[j - 1];
		if (pattern[i] == pattern[j]) {
			pi[i] = ++j;
		}
	}
	return pi;
}

vector<int> KMP(string txt, string pattern) {
	int n = txt.length(), m=pattern.length();

	vector<int>pi = Fail(pattern);
	vector<int> pos;
	for (int i = 0, j = 0; i < n; i++) {
		while (j > 0 && txt[i] != pattern[j])
			j = pi[j - 1];
		if (txt[i] == pattern[j]) {
			if (j == m - 1) {
				pos.push_back(i - m + 1);
				j = pi[j];
			}
			else
				j++;
		}
	}
	return pos;
}

int visited[51];

int main(void) {
	fastio();
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (visited[i])
			continue;
		string pattern = v[i];
		int len = pattern.length();
		for (int j = i + 1; j < N; j++) {
			if (visited[j])
				continue;
			string txt = v[j] + v[j];
			if (len * 2 != txt.length())
				continue;
			vector<int>sol = KMP(txt, pattern);
			if (sol.size() > 0) {
				visited[j] = 1;
			}
		}
		cnt++;
	}
	cout << cnt << '\n';
	return 0;
}