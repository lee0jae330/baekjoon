#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

vector<long long int>v;

long long int para_search(long long int start, long long int end, long long int target) {
	long long int mid;
	while (start+1< end) {
		mid = (start + end) / 2;
		long long int sum = 0;
		for (int i = 0; i < v.size(); i++) {
			long long int result = v[i] / mid;
			sum += result;
		}
		if (sum >= target) {
			start = mid;
		}
		else
			end = mid;
	}
	return start;
}

int main(void) {
	fastio();
	int K, N;
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		long long int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	cout << para_search(1, v[K-1]+1, N) << '\n';
	return 0;
}