#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll A, B, C, X, Y, Z;
	cin >> A >> B >> C >> X >> Y >> Z;
	ll sol = 0;
	while (1) {
		if ((!A && X < 3 || !X && Z < 3) && (!B && Y < 3 || !Y && X < 3) && (!C && Z < 3 || !Z && Y < 3)) {
			cout << sol << '\n';
			return 0;
		}
		/*
		cout << "인원 : " << A << ' ' << B << ' ' << C << '\n';
		cout << "식권 : " << X << ' ' << Y << ' ' << Z << '\n';
		*/

		sol += min(A, X);
		ll tmp = A;
		A = max(tmp - X, 0ll);
		X = max(X - tmp, 0ll);
		sol += min(B, Y);
		tmp = B;
		B = max(tmp - Y, 0ll);
		Y = max(Y - tmp, 0ll);
		sol += min(C, Z);
		tmp = C;
		C = max(tmp - Z, 0ll);
		Z = max(Z - tmp, 0ll);

		if (A == 0 && X >=3) {
			Y += X / 3;
			X %= 3;
		}
		else if (B == 0 && Y >= 3) {
			Z += Y / 3;
			Y %= 3;
		}
		else if (C == 0 && Z >= 3) {
			X += Z / 3;
			Z %= 3;
		}

	}
	return 0;
}