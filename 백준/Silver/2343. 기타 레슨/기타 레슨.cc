#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
vector<int>v;
int sum = 0;

bool determine(int sz) {
	int cnt = 1;
	int tmp = sz;
	for (int n : v) {
		if (n <= tmp) {
			tmp -=n;
		}
		else {
			cnt++;
			if (n <= sz) {
				tmp = sz;
				tmp -=n;
			}
			else {
				return false;
			}
		}
	}
	
	if (cnt <= M) {
		return true;
	}
	return false;
}

int search() {
	int left =0;
	int right = sum;
	int result = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (determine(mid)) {
			result = mid;
			right = mid -1;
		}
		else {
			left = mid + 1;
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		sum +=v[i];
	}
	cout << search() <<'\n';
	return 0;
}