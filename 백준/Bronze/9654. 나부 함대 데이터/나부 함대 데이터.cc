#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	cout << "SHIP NAME      CLASS          DEPLOYMENT IN SERVICE" << '\n';
	cout << "N2 Bomber      Heavy Fighter  Limited    21        " << '\n';
	cout << "J-Type 327     Light Combat   Unlimited  1         " << '\n';
	cout << "NX Cruiser     Medium Fighter Limited    18        " << '\n';
	cout << "N1 Starfighter Medium Fighter Unlimited  25        " << '\n';
	cout << "Royal Cruiser  Light Combat   Limited    4         " << '\n';
	return 0;
}