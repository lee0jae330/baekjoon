#include<iostream>
#include<algorithm>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	while (N--) {
		string a, b;
		cin >> a >> b;

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		if (a == b) {
			cout << "Possible" <<'\n';
		}
		else {
			cout << "Impossible" <<'\n';
		}
	}
	return 0;
}