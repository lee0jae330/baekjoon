#include<iostream>
#include<algorithm>
#include<tuple>
#include<vector>

using namespace std;

int arr[10001];



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i <= 10000; i++) {
		arr[i] = i;
	}

	int N, D;
	cin >> N >> D;
	vector<tuple<int, int, int>>v;
	for (int i = 0; i < N; i++) {
		int  x, y, z;
		cin >> x >> y >> z;
		if (x >= 0 && y >= 0 && x <= D && y <= D) {
			v.push_back({ x,y,z });
		}
	}

	for (int i = 0; i <= 10000; i++) {
		if (i > 0) {
			arr[i] = min(arr[i], arr[i-1]+1);
		}

		for (auto [x, y, z] : v) {
			if (x == i && y <= D) {
				arr[y] = min(arr[y], arr[x] + z);
			}
		}
	}

	cout << arr[D] <<'\n';

	return 0;
}
