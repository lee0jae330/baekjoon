#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[100001];

int main(void) {
	fastio();
	arr[1]=1;
	for (int i = 2; i < 100001; i++) {
		if(arr[i])
			continue;
		for(int j=i+i;j<100001;j+=i)
			arr[j]=1;
	}

	int A,B;
	cin >>A>>B;
	int cnt=0;
	for (int i = A; i <= B; i++) {
		int tmp=i;
		int prime=0;
		while (1) {
			for (int j = 2; j <= sqrt(tmp); j++) {
				if (tmp % j == 0) {
					prime++;
					tmp/=j;
					break;
				}
			}
			if (tmp == 1 || !arr[tmp]) {
				break;
			}
		}
		if(!arr[tmp])
			prime++;
		if (prime&&!arr[prime]) {
			cnt++;
		}
	}
	cout<<cnt <<'\n';
	return 0;
}