#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	vector<int>v(3);
	for (int i = 0; i < 3; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	cout << v[1] + v[2] << '\n';
	return 0;
}