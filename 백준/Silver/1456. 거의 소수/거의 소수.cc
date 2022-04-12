#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[10000001];
vector<long long> prime;

int main(void) {
	fastio();
	arr[1]=1;
	for (long long i = 1; i < 10000001; i++) {
		if(arr[i])
			continue;
		prime.push_back(i);
		for(long long j=i*i;j<10000001;j+=i)
			arr[j]=1;
	}

	long long a, b, cnt=0;
	cin >> a>>b;

	for (int i = 0; i < prime.size(); i++) {
		long long tmp = prime[i];
		while (tmp <= b/prime[i]) {
			tmp *= prime[i];
			if(tmp>=a)
				cnt++;
		}
	}
	cout << cnt <<'\n';
	return 0;
}