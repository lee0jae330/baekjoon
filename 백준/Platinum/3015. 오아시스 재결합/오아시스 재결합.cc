#include<iostream>
#include<vector>
#include<stack>
#include<tuple>

typedef long long ll;

using namespace std;

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

	stack < tuple<int, ll, ll, ll >> s;
	ll sum = 0;

	for (int i = N - 1; i >= 0; i--) {
		if (s.empty()) {
			s.push({ v[i], 0, 0 ,0 });
			continue;
		}

		auto [t, big, same, small] = s.top();
		
		if (t < v[i]) {
			ll cnt = 0;

			int x1 = 0, x2 = 0, x3 = 0;
			while (!s.empty()) {
				auto [tt, x, y, z] = s.top();

				if (tt > v[i]) {
					x1 = 1;
					cnt++;
					break;
				}

				if (tt == v[i]) {
					x2 += (y + 1);
				}
				else {
					x3 += (y + 1);
				}
				s.pop();
			}
			sum += x1;
			sum += x2;
			sum += x3;
			s.push({ v[i], x1, x2, x3 });
		}
		else if (t == v[i]) {
			ll tmp = big + same + 1;
			sum += tmp;
			s.pop();
			s.push({ v[i], big, same + 1, 0 });
		}
		else {
			sum++;
			s.push({ v[i], 1, 0 , 0 });
		}
	}
	cout << sum << '\n';
	return 0;
}