#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>

using namespace std;

vector<pair<int, int>>v;
vector<int>lis;


bool comp1(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

bool comp2(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first > b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	int hx, hy, wx, wy;
	cin >> hx >> hy >> wx >> wy;

	if (hx == wx && hy == wy) {
		for (int i = 0; i < N; i++) {
			int x, y;
			cin >> x >> y;
			if (x == hx && y == hy) {
				v.push_back({ x,y });
			}
		}
		cout << v.size() <<'\n';
	}
	else if (hx == wx) {
		if (hy < wy) {
			for (int i = 0; i < N; i++) {
				int x, y;
				cin >> x >> y;
				if (x == hx && hy <= y && y <= wy) {
					v.push_back({ x,y });
				}
			}
			sort(v.begin(), v.end());
			for (auto [x, y] : v) {
				auto iter = upper_bound(lis.begin(), lis.end(), y);
				if (iter == lis.end()) {
					lis.push_back(y);
				}
				else {
					*iter = y;
				}
			}
			cout << lis.size() <<'\n';
		}
		else {
			// hy > wy
			for (int i = 0; i < N; i++) {
				int x, y;
				cin >> x >> y;
				if (x == hx && wy <= y && y <= hy) {
					v.push_back({ x, -y });
				}
			}
			sort(v.begin(), v.end());
			for (auto [x, y] : v) {
				auto iter = upper_bound(lis.begin(), lis.end(), y);
				if (iter == lis.end()) {
					lis.push_back(y);
				}
				else {
					*iter = y;
				}
			}
			cout << lis.size() << '\n';
		}
	}
	else if (hy == wy) {
		if (hx < wx) {
			for (int i = 0; i < N; i++) {
				int x, y;
				cin >> x >> y;
				if (hx <= x && x <= wx && y == hy) {
					v.push_back({ x,y });
				}
			}

			sort(v.begin(), v.end(), comp1);
			for (auto [x, y] : v) {
				auto iter = upper_bound(lis.begin(), lis.end(), x);
				if (iter == lis.end()) {
					lis.push_back(x);
				}
				else {
					*iter = x;
				}
			}
			cout << lis.size() << '\n';
		}
		else {
			// hx > wx
			for (int i = 0; i < N; i++) {
				int x, y;
				cin >> x >> y;
				if (wx <= x && x <= hx && y == hy) {
					v.push_back({ -x,y });
				}
			}

			sort(v.begin(), v.end(), comp1);
			for (auto [x, y] : v) {
				auto iter = upper_bound(lis.begin(), lis.end(), x);
				if (iter == lis.end()) {
					lis.push_back(x);
				}
				else {
					*iter = x;
				}
			}
			cout << lis.size() << '\n';

		}
	}
	else if ((hx < wx && hy < wy) || (hx > wx && hy < wy)) {
		for (int i = 0; i < N; i++) {
			int x, y;
			cin >> x >> y;
			int x1 = min(hx, wx);
			int x2 = max(hx, wx);
			int y1 = min(hy, wy);
			int y2 = max(hy, wy);

			if (x1 <= x && x <= x2 && y1 <= y && y <= y2) {
				v.push_back({ x,y });
			}
		}
		if (hx < wx && hy < wy) {
			sort(v.begin(), v.end());
			
			for (auto [x, y] : v) {
				auto iter = upper_bound(lis.begin(), lis.end(), y);
				if (iter == lis.end()) {
					lis.push_back(y);
				}
				else {
					*iter = y;
				}
			}
		}
		else {
			sort(v.begin(), v.end(), comp2);

			for (auto [x, y] : v) {
				auto iter = upper_bound(lis.begin(), lis.end(), y);
				if (iter == lis.end()) {
					lis.push_back(y);
				}
				else {
					*iter = y;
				}
			}
		}
		cout << lis.size() <<'\n';
	}
	else {
		for (int i = 0; i < N; i++) {
			int x, y;
			cin >> x >> y;
			int x1 = min(hx, wx);
			int x2 = max(hx, wx);
			int y1 = min(hy, wy);
			int y2 = max(hy, wy);

			if (x1 <= x && x <= x2 && y1 <= y && y <= y2) {
				v.push_back({ x, -y });
			}
		}

		if (hx < wx && hy > wy) {
			sort(v.begin(), v.end());

			for (auto [x, y] : v) {
				auto iter = upper_bound(lis.begin(), lis.end(), y);
				if (iter == lis.end()) {
					lis.push_back(y);
				}
				else {
					*iter = y;
				}
			}
		}
		else {
			sort(v.begin(), v.end(),comp2);

			for (auto [x, y] : v) {
				auto iter = upper_bound(lis.begin(), lis.end(), y);
				if (iter == lis.end()) {
					lis.push_back(y);
				}
				else {
					*iter = y;
				}
			}
		}
		cout << lis.size() <<'\n';
	}


	return 0;

}