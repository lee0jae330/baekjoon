#include<iostream>
#include<cstdlib>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int cow[200001];
int arr[200001];
int Minus[200001];

int main(void) {
	fastio();
	int N, Q;
	cin >> N >> Q;
	for (int i = 0; i < N; i++)
		cin >> cow[i];
	for (int i = 0; i < N; i++) {
		arr[i] = cow[i % N] * cow[(i + 1) % N] * cow[(i + 2) % N] * cow[(i + 3) % N];
	}
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		sum += arr[i];
	}
	while (Q--) {
		int n;
		cin >> n;
		n--;
		for (int i = 0; i < 4; i++) {
			int tmp=n-i;
			if (tmp < 0) {
				tmp = N + tmp;
				
			}
			arr[tmp] = -arr[tmp];
			sum += 2 * arr[tmp];
		}
		cout << sum << '\n';
	}
	return 0;
}