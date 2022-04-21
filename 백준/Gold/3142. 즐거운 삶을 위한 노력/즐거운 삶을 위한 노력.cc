#include<iostream>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<set>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

map<int, int>m;
int arr[1000001];
int cnt[1000001];
vector<int>prime;
set<int>s;
int main(void) {
	fastio();
	arr[1] = 1;
	for (long long i = 2; i < 1000001; i++) {
		if (arr[i])
			continue;
		arr[i] = i;
		prime.push_back(i);
		for (long long j = i * i; j < 1000001; j += i)
			arr[j] = i;
	}
	int N=500000;
	cin >> N;
	long long sum = 0;
	while (N--) {
		int num=999999;
		cin >> num;
		while (num != 1) {
			int tmp = arr[num];
			if (!cnt[tmp]) {
				sum++;
				cnt[tmp]++;
			}
			else {
				sum--;
				cnt[tmp]--;
			}
			num /= arr[num];
		}
		/*while (1) {
			for (int i = 0; i < prime.size(); i++) {
				if (num % prime[i] == 0) {
					if (cnt[prime[i]] % 2 == 0) {
						sum++;
						cnt[prime[i]]++;
					}
					else {
						sum--;
						cnt[prime[i]]++;
					}
					num /= prime[i];
				}
				if (num < prime[i])
					break;
			}
			if (num == 1)
				break;
		}*/
		if (sum == 0)
			cout << "DA" << '\n';
		else
			cout << "NE" << "\n";
	}
	return 0;
}