#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int cost[14];

int main(void) {
	int money;
	cin >> money;
	int a = money, b = money;
	for (int i = 0; i < 14; i++)
		cin >> cost[i];
	int stockA = 0, stockB = 0;
	for (int i = 0; i < 14; i++) {
		if (cost[i] <= a) {
			stockA += a / cost[i];
			a %= cost[i];
		}
	}
	int flag = 0;
	for (int i = 1; i < 14; i++) {
		if (cost[i - 1] < cost[i]) { //전일대비 상승
			if (flag < 0) {
				flag = 0;
			}
			flag++;
		}
		else if (cost[i - 1] > cost[i]) { //전일 대비 하락
			if (flag > 0)
				flag = 0;
			flag--;
		}
		else {
			flag = 0;
		}

		if (flag >= 3) {
			if (stockB > 0) {
				b += stockB * cost[i];
				stockB = 0;
			}
		}
		if (flag <= -3) {
			if (cost[i] < b) {
				stockB += b / cost[i];
				b %= cost[i];
			}
		}
	}
	int totalA =a+ cost[13] * stockA;
	int totalB = b + cost[13] * stockB;
	//cout << totalA << ' ' << totalB << '\n';
	if (totalA > totalB)
		cout << "BNP" << '\n';
	else if (totalA < totalB)
		cout << "TIMING" << '\n';
	else
		cout << "SAMESAME" << '\n';
	return 0;
}