#include<iostream>
#include<algorithm>

using namespace std;

int main(void) {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int a1, b1, a2, b2;
	cin >> a1 >> b1 >> a2 >> b2;
	int max_x = max(x2, a2);
	int min_x = min(x1, a1);
	int x = max_x - min_x;

	int max_y = max(y2, b2);
	int min_y = min(y1, b1);
	int y = max_y - min_y;

	int result = max(x, y);
	cout << result * result << '\n';
	return 0;
}