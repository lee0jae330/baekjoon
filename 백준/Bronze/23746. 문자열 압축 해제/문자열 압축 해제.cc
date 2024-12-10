#include<iostream>
#include<string>
#include<map>

using namespace std;

map<string, string>m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	while (N--) {
		string value, key;
		cin >> value >> key;
		m.insert({ key, value });
	}

	string str;
	cin >> str;

	string sol = "";
	for (int i = 0; i < str.length(); i++) {
		string key = string(1,str[i]);
		sol += m[key];
	}
	
	int S, E;
	cin >> S >> E;
	cout << sol.substr(S - 1, E-S+1) << '\n';
	return 0;

}