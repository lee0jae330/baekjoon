#include<iostream>
#include<cstring>
#include<string>
#include<set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	set<string>s1 = {"social", "history", "language", "literacy"};
	set<string>s2 = { "bigdata", "public", "society"};

	string str;
	getline(cin, str);

	for (string s : s1) {
		if (str.find(s) != string::npos) {
			cout << "digital humanities";
			return 0;
		}
	}

	for (string s : s2) {
		if (str.find(s) != string::npos) {
			cout << "public bigdata";
			return 0;
		}
	}
	
	
	return 0;
}