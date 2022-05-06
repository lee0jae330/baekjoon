#include<iostream>
#include<string>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	string s, fan = ":fan:";
	cin >> s;
	s = ":"+ s +":";
	cout << fan << fan << fan << '\n';
	cout << fan << s << fan << '\n';
	cout << fan << fan << fan << '\n';
	return 0;
}