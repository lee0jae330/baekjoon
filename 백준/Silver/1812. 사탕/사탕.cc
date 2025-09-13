#include<iostream>
#include<vector>
#include<numeric>

typedef long long ll;

using namespace std;

vector<ll> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll N;
	cin >> N;

	v.resize(N);

	for (ll i = 0; i < N; i++) {
		cin >> v[i];
	}

	ll total = accumulate(v.begin(), v.end(), 0) / 2;
	vector<int>arr(N);

	for (int i = 0; i < N; i++) {
		int tmp = total - v[i];
		int cnt = 2;

		int next = (i + 2) % N;

		while (cnt < N - 1) {
			tmp -= v[next];
			next += 2;
			next %=N;
			cnt +=2;
		}


		if (tmp < 0) {
			continue;
		}

		arr[N-1] = tmp;

		int flag = 0;

		for (int x = 0; x < N - 1; x++) {
			if (!x) {
				arr[x] = v[N - 1] - arr[N - 1];

			}
			else {
				arr[x] = v[x - 1] - arr[x - 1];
			}

			if (arr[x] < 0) {
				flag=1;
			}
		}

		if (flag) {
			continue;
		}
		else {
			for (auto num : arr) {
				cout << num << '\n';
			}
			return 0;
		}
		
	}

	


	return 0;
}