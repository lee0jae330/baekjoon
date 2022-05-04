#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int y;
	cin >> y;
	if (y == 1995 || y == 1998 || y == 1999 || y >= 2001 && y <= 2005||y>=2009&&y<=2012||y>=2014&&y<=2017||y==2019)
		cout << "ITMO" << '\n';
	else if (y == 1996 || y == 1997 || y == 2000||y==2007||y==2008||y==2013||y==2018)
		cout << "SPbSU" << '\n';
	else if (y == 2006)
		cout << "PetrSU, ITMO" << '\n';

	return 0;

}