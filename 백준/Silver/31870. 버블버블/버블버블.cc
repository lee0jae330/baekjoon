#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool comp(const int& a, const int& b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;

	cin >> N;

	vector<int>v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	vector<int>asc = v;
	vector<int>dec = v;

	sort(asc.begin(), asc.end());
	sort(dec.begin(), dec.end(), comp);

	int cnt1 = 0;
	int cnt2 = 0;

	vector<int>tmp = v;

	while (!equal(v.begin(), v.end(), asc.begin())) {
		for (int i = 0; i < N - 1; i++) {
			if (v[i] > v[i + 1]) {
				swap(v[i], v[i + 1]);
				cnt1++;
				break;
			}
		}
	}

	v = tmp;

	while (!equal(v.begin(), v.end(), dec.begin())) {
		for (int i = 1; i < N; i++) {
			if (v[i] > v[i - 1]) {
				swap(v[i], v[i - 1]);
				cnt2++;
				break;
			}
		}
	}

	cout << min(cnt1, cnt2 + 1) << '\n';
	return 0;
}