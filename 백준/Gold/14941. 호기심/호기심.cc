#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[100001];
vector<long long>prime;

int main(void) {
	fastio();
	arr[1]=1;
	for (long long i = 2; i < 100001; i++) {
		if(arr[i])
			continue;
		prime.push_back(i);
		for(long long j=i*i;j<100001;j+=i)
			arr[j]=1;
	}

	int N;
	cin >>N;
	while (N--) {
		int a, b;
		long long sum=0;
		cin >>a >>b;
		auto iter1= lower_bound(prime.begin(),prime.end(),a);
		
		auto iter2= lower_bound(prime.begin(),prime.end(),b);
		if(iter2==prime.end())
			iter2--;
		if (a == b && *iter1 > a) {
			cout << sum <<'\n';
			continue;
		}
		if (*iter2 > b) {
			iter2--;
		}
		//cout << *iter1<<'\n';
		int num=0;
		for (auto it = iter1; it <= iter2; it++) {
			int tmp=*it;
			if (num % 2 == 0) {
				sum+=3*tmp;
			}
			else {
				sum-=tmp;
			}
			num++;
		}
		cout << sum <<'\n';
	}
	return 0;
}