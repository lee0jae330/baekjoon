#include<iostream>
#include<cmath>
#include<memory.h>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

long long arr[1000001];
long long sum[1000001];

int main(void) {
	fastio();
	arr[1]=1;
	for (long long i = 2; i < 1000001; i++) {
		arr[i]+=i+1;
		for (long long j = i+i; j < 1000001; j+=i) {
			arr[j]+=i;
		}
	}
	sum[1]=arr[1];
	for (int i = 2; i < 1000001; i++) {
		sum[i]=arr[i]+sum[i-1];
	}

	int T;
	cin >>T;
	while (T--) {
		int num;
		cin >>num;
		cout << sum[num]<<'\n';
	}
	return 0;
}