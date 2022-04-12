#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[2000001];
vector<int>prime;

int main(void) {
	fastio();
	arr[1] = 1;
	for (long long i = 2; i < 2000001; i++) {
		if (arr[i])
			continue;
		prime.push_back(i);
		for (long long j = i * i; j < 2000001; j += i)
			arr[j] = 1;
	}
	int T;
	cin >> T;
	while (T--) {
		long long A, B;
		cin >> A >> B;
		long long sum = A + B;
		if (sum == 2 || sum == 3) {
			cout << "NO" << '\n';
			continue;
		}
		if (sum % 2 == 1) {
			sum -= 2;
			int flag = 0;

			for (int i = 0; i < prime.size(); i++) {
				if (sum % prime[i] == 0) {
					sum/=prime[i];
					flag = 1;
					break;
				}
			}
			if (!flag||sum==1)
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
		else {
			cout << "YES" << '\n';
		}
	}
	return 0;
}