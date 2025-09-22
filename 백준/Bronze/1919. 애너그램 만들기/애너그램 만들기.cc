#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string a, b;
	cin >> a >> b;

	vector<int>v1(26,0);
	vector<int>v2(26, 0);


	for (char c : a) {
		v1[c - 'a']++;
	}
	for (char c : b) {
		v2[c - 'a']++;
	}

	int sol = 0;

	for(int i =0 ;i<26;i++) {
		sol += abs(v1[i]-v2[i]);
	}

	cout << sol << '\n';
	return 0;
}