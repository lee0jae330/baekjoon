#include<iostream>
#include<cmath>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[1000001];
int cnt[1000001];

int main(void) {
	fastio();
	arr[1] = 1;
	for (long long i = 2; i < 1000001; i++) {
		if (arr[i])
			continue;
		arr[i] = i;
		for (long long j = i * i; j < 1000001; j += i)
			arr[j] = i;
	}
	int N;
	cin >> N;
	long long sum = 0;
	while (N--) {
		int num;
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
		
		if (sum == 0)
			cout << "DA" << '\n';
		else
			cout << "NE" << "\n";
	}
	return 0;
}