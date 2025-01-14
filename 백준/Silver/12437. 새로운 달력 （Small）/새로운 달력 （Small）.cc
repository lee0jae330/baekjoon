#include<iostream>
#include<set>
#include<vector>
#include<cmath>
using namespace std;

vector<int>v;
set<int>s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		v.clear();
		s.clear();
		int A, B, C;
		cin >> A >> B >> C;
		int flag = 0;
		while (1) {
			if (s.find(B + flag) != s.end()) {
				break;
			}
			v.push_back((int)ceil((double)(B + flag) / (double)C));
			s.insert(B + flag);
			flag = (B + flag) % C;
		}

		int x = A / v.size();
		int y = A % v.size();

		int sum = 0, total = 0;
		for (int num : v) {
			sum += num;
		}
		total = x * sum;
		if (!v.empty()) {
			for (int i = 0; i < y; i++) {
				total += v[i];
			}
		}

		cout << "Case #"<< t<< ": "<< total << '\n';
	}
	return 0;
}