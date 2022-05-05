#include<iostream>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


int main(void) {
	fastio();
	int x, y, z, a, b, c;
	cin >> x >> y >> z >> a >> b >> c;
	char grade='E';
	if (z <= c) {
		int flag = 0;
		if (y % 2)
			flag = 1;
		if (y / 2+flag <= b)
			grade = 'D';
		if (y <= b) {
			grade = 'C';
			flag = 0;
			if (x % 2)
				flag = 1;
			if (x / 2 + flag <= a)
				grade = 'B';
			if (x <= a)
				grade = 'A';
		}
	}
	cout << grade << '\n';
		
	return 0;
}