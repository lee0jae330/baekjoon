#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N,T;
	int arr[1001];
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int cnt =0;
	for (int i = 0; i < N; i++) {
		if (arr[i] > T) {
			cnt += arr[i] - T;
		}
		else  if (T % arr[i]) {
			int tmp1 = 1;
			while (1) {
				if (T % (arr[i] + tmp1)) {
					tmp1++;
				}
				else {
					break;
				}
			}
			int tmp2 =1;
			while (1) {
				if (T % (arr[i] - tmp2)) {
					tmp2++;
				}
				else {
					break;
				}
			}
			cnt += min(tmp1, tmp2);
		}
	}
	cout << cnt <<'\n';
	return 0;
}