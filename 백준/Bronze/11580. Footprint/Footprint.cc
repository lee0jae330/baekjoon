#include<iostream>
#include<utility>
#include<set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	string str;
	cin >> str;
	int x = 0, y = 0;
	set <pair<int, int>>s;
	s.insert({ x,y });
	for (char c : str) {
		switch (c) {
		case 'N':
			y++;
			break;
		case 'E':
			x--;
			break;
		case 'W':
			x++;
			break;
		default:
			y--;
		}
		s.insert({ x,y });
	}
	cout << s.size();
	return 0;
}
