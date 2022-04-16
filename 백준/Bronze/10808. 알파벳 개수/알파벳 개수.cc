#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[27];

int main(void) {
	fastio();
	string str;
	cin >>str;
	for (int i = 0; i < str.length(); i++) {
		arr[str[i]-'a']++;
	}
	for (int i = 0; i < 26; i++) {
		cout << arr[i]<<' ';
	}
	cout <<'\n';
	return 0;
}