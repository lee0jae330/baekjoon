#include<iostream>
#include<math.h>

using namespace std;

int  main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, e;
	cin >> n >> e;
	int sum1 =0 , sum2 =0;
	for (int i = 0; i < n-1; i++) {
		int tmp;
		cin >>tmp;
		sum1+=tmp;
	}

	for (int i = 0; i < e - 1; i++) {
		int tmp;
		cin >> tmp;
		sum2+=tmp;
	}

	int result = 0 ;
	if (sum1 && sum2) {
		result = ceil(sqrt(sum1 * sum1 + sum2 * sum2));
		
	}
	else if (sum1 || sum2) {
		result = sum1+sum2;
	}
	cout << result << '\n';
	return 0;
}