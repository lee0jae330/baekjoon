#include<iostream>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string a, b,c;
	cin >> a >> b>> c;

	int flag = 0;
	string s;
	for(char t : a) {
		if (t >= '0' && t <= '9') {
			flag = 1;
			s= a;
		}
	}

	for (char t : b) {
		if (t >= '0' && t <= '9') {
			flag = 2;
			s=b;
		}
	}

	for (char t : c) {
		if (t >= '0' && t <= '9') {
			flag = 3;
			s=c;
		}
	}

	int num = stoi(s) + 4 - flag;
	
	if (num % 3 == 0 && num % 5 == 0) {
		cout << "FizzBuzz" <<'\n';
	}
	else if (num % 3 == 0) {
		cout << "Fizz" <<'\n';
	}
	else if (num % 5 == 0) {
		cout << "Buzz" <<'\n';
	}
	else {
		cout << num<<'\n';
	}

	return 0;
}