#include<iostream>
#include<set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	while (N--) {
		int sol = 0;

		int m;
		cin >> m;
		set<int>l;
		set<int>r;

		int num;
		for (int i = 0; i < m; i++) {
			cin >> num;
			l.insert(num);
		}
		for (int j = 0; j < m; j++) {
			cin >> num;
			r.insert(num);
		}

		while (1) {
			if (l.empty() || r.empty()) {
				break;
			}

			int num = *l.begin();
			l.erase(num);

			auto iter = l.find(num + 500);
			if (iter != l.end()) {
				num = *iter;
				l.erase(num);
			}
			else {
				continue;
			}


			auto it = r.find(num + 500);

			if (it != r.end()) {
				num = *it;
				r.erase(num);
			}

			else {
				continue;
			}


			it = r.find(num + 500);
			if (it != r.end()) {
				r.erase(*it);
			}
			else {
				continue;
			}
			sol++;
		}
		cout << sol << '\n';
	}
	return 0;
}