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

vector<int>Fail(string pattern) {
	int m = pattern.length();

	vector<int>pi(m);
	pi[0] = 0;

	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && pattern[i] != pattern[j])
			j = pi[j - 1];
		if (pattern[i] == pattern[j])
			pi[i] = ++j;
	}

	return pi;
}

vector<int>KMP(string text, string pattern) {
	int n = text.length();
	int m = pattern.length();
	int real_n=n/2;
	vector<int>pi = Fail(pattern);
	vector<int>pos;

	for (int i = 0, j = 0; i < n; i++) {
		while (j > 0 && text[i] != pattern[j])
			j = pi[j - 1];
		if (text[i] == pattern[j]) {
			if (j == m - 1) {
				pos.push_back(i - m + 1);
				j = pi[j];
			}
			else
			{
				j++;
			}
		}
	}
	return pos;
}

int gcd(int a, int b) {
	int tmp;
	if (a < b)
		swap(a, b);
	while (b != 0) {
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

int main(void) {
	fastio();
	int N;
	cin >> N;
	string pattern, text;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		pattern += s;
	}

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		text += s;
	}

	text += text;

	vector<int>kmp = KMP(text, pattern);
	int sz = kmp.size();
	for (int i = 0; i < sz; i++) {
		if(kmp[i]>=N)
			sz--;
	}
	int GCD = gcd(sz, N);
	if (N == 1) {
		cout << 1<<'/'<<1<<'\n';
		return 0;
	}
	cout << sz / GCD << '/' << N / GCD << '\n';
	return 0;
}