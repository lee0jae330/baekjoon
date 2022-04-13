#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[1000001];

int main(void) {
	fastio();
	arr[1]=1;
	for (long long i = 2; i < 1000001; i++) {
		if(arr[i])
			continue;
		for(long long j=i*i;j<1000001;j+=i)
			arr[j]=1;
	}
	int N;
	cin >>N;
	unsigned long long result = -1;
	while (N--) {
		long long num ;
		cin >> num;
		if (!arr[num]) {
			if (result == -1) {
				result=1;
			}
			result *= num;
			arr[num]=1;
		}
	}
	if(result==-1)
		 cout << -1<<'\n';
	else
		cout <<result <<'\n';
	return 0;
}