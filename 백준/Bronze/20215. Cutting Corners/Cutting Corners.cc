#include<iostream>
#include<cmath>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


int main(void) {
	double w, h;
	cin >> w >> h;
	double area1 = w + h, area2=sqrt(w*w+h*h);
	cout.precision(12);
	cout << area1 - area2;
	return 0;
}