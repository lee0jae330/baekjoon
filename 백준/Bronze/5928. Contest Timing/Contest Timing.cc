#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int D, H, M,result=0;
	cin >> D >> H >> M;
	if (D == 11) {
		if (H < 11 || H == 11 && M < 11) {
			cout << -1 << '\n';
			return 0;
		}
		int h = H - 11;
		int m = M - 11;
		result = h * 60 + m;
		
	}
	else {
		if (D > 12) {
			int gap = D - 12;
			result += 1440 * gap;
		}

		result += 769;
		result += H * 60 + M;
	}
	cout << result << '\n';
	return 0;
}