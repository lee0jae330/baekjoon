#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	cin >> str;
	
	int pos = str.find(".");
	str.erase(0,pos+1);
	int length = str.length();
	cout << fixed;
	cout.precision(0);
	cout << "YES" <<'\n';
	cout << stoi(str) << ' ' << pow(10,length) << '\n';
	return 0;
}