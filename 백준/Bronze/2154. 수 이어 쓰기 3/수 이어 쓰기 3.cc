#include<iostream>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	string str;
	for (int i = 1; i <= 1e5; i++) {
		str += to_string(i);
	}
	string s;
	cin >> s;
	cout << str.find(s) + 1;
	return 0;
}