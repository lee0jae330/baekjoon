#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, L,R;
	cin >> N >> L >> R;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	vector<int>tmp=arr;
	sort(tmp.begin(), tmp.end());
	
	sort(arr.begin()+L-1,arr.begin()+R);

	if (tmp == arr) {
		cout << 1 <<'\n';
	}
	else {
		cout << 0 <<'\n';
	}
}