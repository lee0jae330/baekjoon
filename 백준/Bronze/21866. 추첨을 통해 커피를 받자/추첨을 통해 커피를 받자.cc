#include<iostream>
#include<cstdlib>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[10];
int score[10] = { 0,100,100,200,200,300,300,400,400,500 };

int main(void) {
	fastio();
	int flag = 0,total=0;
	for (int i = 1; i <= 9; i++) {
		cin >> arr[i];
		if (arr[i] > score[i])
			flag = 1;
		else {
			total += arr[i];
		}
	}
	if (flag)
		cout << "hacker" << '\n';
	else {
		if (total >= 100)
			cout << "draw" << '\n';
		else
			cout << "none" << '\n';
	}
	return 0;
}