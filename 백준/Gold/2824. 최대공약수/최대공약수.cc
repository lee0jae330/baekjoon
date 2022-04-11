#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

map<int, int>A;
map<int, int>B;

int main(void) {
	fastio();
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num <= 3) {
			if (num != 1) {
				A[num]++;
			}
			continue;
		}
		while (num > 1) {
			int flag = 0;
			for (int j = 2; j <= sqrt(num); j++) {
				if (num % j == 0) {
					A[j]++;
					flag = 1;
					num /= j;
					break;
				}
			}
			if (!flag)
				break;
		}
		if (num == 1)
			continue;
		A[num]++;
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		if (num <= 3) {
			if (num != 1) {
				B[num]++;
			}
			continue;
		}
		while (num > 1) {
			int flag = 0;

			for (int j = 2; j <= sqrt(num); j++) {
				if (num % j == 0) {
					B[j]++;
					num /= j;
					flag = 1;
					break;
				}
			}
			if (!flag)
				break;
		}
		if (num == 1)
			continue;
		B[num]++;
	}


	long long tmp = 1;
	int f = 0;
	auto a= A.begin(), b= B.begin();
	while (a != A.end() && b != B.end()) {
		if(a->first>b->first)
			b++;
		else if(a->first<b->first)
			a++;
		else {
			int cnt = min(a->second, b->second);
			while (cnt--) {
				tmp *= a->first;
				if (tmp >= 1000000000) {
					f=1;
					tmp%=1000000000;
				}
			}
			a++;
			b++;
		}
	}
	string str = to_string(tmp);
	if (f) {
		for (int i = 0; i < 9 - str.length(); i++)
			cout << 0;
	}
	cout << tmp << '\n';
	return 0;
}