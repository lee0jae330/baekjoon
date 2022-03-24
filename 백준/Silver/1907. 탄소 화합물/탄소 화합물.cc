#include<iostream>
#include<string>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	string str;
	cin >> str;
	int plus, eq;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '+')
			plus = i;
		if (str[i] == '=')
			eq = i;
	}
	string s1, s2, s3;
	s1 = str.substr(0, plus);
	s2 = str.substr(plus + 1, eq - plus-1);
	s3 = str.substr(eq + 1, str.length()-1 - eq);
	int c1=0, c2=0, c3=0, h1=0, h2=0, h3=0, o1=0, o2=0, o3=0;

	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] == 'C') {
			if (i < s1.length() - 1) {
				if (s1[i + 1] >= '0' && s1[i + 1] <= '9')
					c1 += (s1[i + 1] - '0');
				else c1++;
			}
			else 
				c1++;
		}
		else if (s1[i] == 'H') {
			if (i < s1.length() - 1) {
				if (s1[i + 1] >= '0' && s1[i + 1] <= '9')
					h1 += (s1[i + 1] - '0');
				else h1++;

			}
			else
				h1++;
		}
		else if (s1[i] == 'O') {
			if (i < s1.length() - 1) {
				if (s1[i + 1] >= '0' && s1[i + 1] <= '9')
					o1 += (s1[i + 1] - '0');
				else o1++;

			}
			else
				o1++;
		}
		else
			continue;
	}
	for (int i = 0; i < s2.length(); i++) {
		if (s2[i] == 'C') {
			if (i < s2.length() - 1) {
				if (s2[i + 1] >= '0' && s2[i + 1] <= '9')
					c2 += (s2[i + 1] - '0');
				else c2++;

			}
			else
				c2++;
		}
		else if (s2[i] == 'H') {
			if (i < s2.length() - 1) {
				if (s2[i + 1] >= '0' && s2[i + 1] <= '9')
					h2 += (s2[i + 1] - '0');
				else h2++;

			}
			else
				h2++;
		}
		else if (s2[i] == 'O') {
			if (i < s2.length() - 1) {
				if (s2[i + 1] >= '0' && s2[i + 1] <= '9')
					o2 += (s2[i + 1] - '0');
				else o2++;
			}
			else
				o2++;
		}
		else
			continue;
	}
	for (int i = 0; i < s3.length(); i++) {
		if (s3[i] == 'C') {
			if (i < s3.length() - 1) {
				if (s3[i + 1] >= '0' && s3[i + 1] <= '9')
					c3 += (s3[i + 1] - '0');
				else c3++;

			}
			else
				c3++;
		}
		else if (s3[i] == 'H') {
			if (i < s3.length() - 1) {
				if (s3[i + 1] >= '0' && s3[i + 1] <= '9')
					h3 += (s3[i + 1] - '0');
				else h3++;

			}
			else
				h3++;
		}
		else if (s3[i] == 'O') {
			if (i < s3.length() - 1) {
				if (s3[i + 1] >= '0' && s3[i + 1] <= '9')
					o3 += (s3[i + 1] - '0');
				else o3++;

			}
			else
				o3++;
		}
		else
			continue;
	}
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			for (int k = 1; k < 11; k++) {
				if (c1 * i + c2 * j == c3 * k && h1 * i + h2 * j == h3 * k && o1 * i + o2 * j == o3 * k) {
					cout << i <<' '<< j <<' ' << k<<'\n';
					return 0;
				}
			}
		}
	}
	return 0;
}