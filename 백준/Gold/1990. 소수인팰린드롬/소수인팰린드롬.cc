#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[10000001];

int main(void) {
	fastio();
	arr[1]=1;
	for (int i = 2; i <=10000000; i++) {
		if(arr[i])
			continue;
		for(int j=i+i;j<=10000000;j+=i)
			arr[j]=1;
	}
	int N,M;
	cin >>N>>M;
	if (M < 10000000) {
		for (int i = N; i <= M; i++) {
			if (!arr[i]) {
				string s1 = to_string(i);
				string s2 = s1;
				reverse(s2.begin(), s2.end());
				if (s1 == s2) {
					cout << stoi(s1) << '\n';
				}
			}

		}

	}
	else {
		for (int i = N; i <= 10000000; i++) {
			if (!arr[i]) {
				string s1 = to_string(i);
				string s2 = s1;
				reverse(s2.begin(), s2.end());
				if (s1 == s2) {
					cout << stoi(s1) << '\n';
				}
			}

		}
	}

	cout <<-1<<'\n';
	return 0;
}