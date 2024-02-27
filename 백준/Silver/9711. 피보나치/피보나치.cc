#include<bits/stdc++.h>

using namespace std;

long long pibo[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	int cnt =1;
	while (T--) {
		int P,Q;
		cin >> P >> Q;
		pibo[0] = 1;
		pibo[1] = 1;
		for (int i = 2; i <= P; i++) {
			pibo[i] = pibo[i - 1] + pibo[i - 2];
			pibo[i]%=Q;
		}
		
		cout << "Case #"<<cnt++<<": " <<pibo[P-1] % Q<< '\n';
	}
	return 0;
}