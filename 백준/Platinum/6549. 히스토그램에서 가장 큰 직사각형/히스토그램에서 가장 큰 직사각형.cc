#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
#include<utility>
#include<tuple>

using namespace std;

typedef long long ll;

vector<int>v;
vector<int>l;
vector<int>r;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (1) {
		v.clear();
		l.clear();
		r.clear();

		int N;
		cin >> N;
		while (!N) {
			return 0;
		}
		
		v.resize(N);
		l.resize(N);
		r.resize(N);

		for (int i = 0; i < N; i++) {
			cin >> v[i];
		}

		ll sol = -1;
		
		stack<tuple<int,int,int>>s;

		for (int i = 0; i < N; i++) {
			if (s.empty()) {
				s.push({v[i], i, 0});
				continue;
			}
			
			if (get<0>(s.top()) >= v[i]) {
				int cnt = 0;
				while (!s.empty()) {
					auto [t, idx, c] = s.top();
					if (t < v[i]) {
						break;
					}
					cnt += c + 1;
					l[idx] = c;
					s.pop();
				}
				s.push({v[i], i, cnt});
			}
			else {
				s.push({v[i], i, 0});
			}
		}

		while (!s.empty()) {
			auto [t, idx, c] = s.top();
			l[idx] = c;
			s.pop();
		}

		for (int i = N-1; i >=0; i--) {
			if (s.empty()) {
				s.push({ v[i], i, 0 });
				continue;
			}

			if (get<0>(s.top()) >= v[i]) {
				int cnt = 0;
				while (!s.empty()) {
					auto [t, idx, c] = s.top();
					if (t < v[i]) {
						break;
					}
					cnt += (c + 1);
					r[idx] = c;
					s.pop();
				}
				s.push({ v[i], i, cnt });
			}
			else {
				s.push({ v[i], i, 0 });
			}
		}

		while (!s.empty()) {
			auto [t, idx, c] = s.top();
			r[idx] = c;
			s.pop();
		}

		for (int i = 0; i < N; i++) {
			ll cnt = l[i] + r[i] +1;
			sol = max(sol, cnt * v[i]);
		}

		cout << sol <<'\n';
	}
}