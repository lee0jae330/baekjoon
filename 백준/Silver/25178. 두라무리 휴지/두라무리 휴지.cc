#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int arr1[26];
int arr2[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	string s1, s2;
	cin >> s1 >> s2;
	
	string tmp1, tmp2;
	for (char c : s1) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
			continue;
		}
		tmp1.push_back(c);
	}
	for (char c : s2) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
			continue;
		}
		tmp2.push_back(c);
	}
	
	if (tmp1 != tmp2) {
		cout << "NO";
		return 0;
	}

	if (s1[0] != s2[0] || s1[N - 1] != s2[N - 1]) {
		cout << "NO";
		return 0;
	}

	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());

	if (s1 != s2) {
		cout << "NO";
		return 0;
	}
	cout << "YES";
	return 0;
}